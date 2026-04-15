# Question 
```
Problem:
Build a Movie Search Page in React.
Fetch paginated results from an API.
Implement search, pagination, and IMDB links.

Topics Covered:
- API calls & pagination
- State management in React (useState, useEffect)
- Performance optimizations

Follow-ups:
- How would you handle large datasets efficiently?
- How would you improve the UX?
- How would you structure this for production?
```

## Brainstorm and Solution 

### Functional Requirements 
- What API will we use for movie search?
- What parameters does the API support?
    searchTerm
    page
    pageSize
- What fields should we display for each movie?
    Title
    Poster
    Year
    IMDB link
- How many results per page?
- Should pagination be next/prev or page numbers?

### Non Functionl Requirements

Ask about:
- Loading state
- Error state
- Empty results
- Debouncing search input

Example:
    "Should we handle loading states and error messages when API fails?"


### Concepts - 
- What is debouncing
    It is dealying a functino call until user stops doing an action for a certan time., function call to deliver a final value
- Debouncing reduces the number of API calls by waiting for the user to stop typing before sending the request.
- Debounce example
```
const debounce = function(fn, delay) { // here fn is the function we want to delay
    let timer;
    return function () {
        clearTimeOut(timer);
        timer = setTimeOut(() => { // setTimeOut function returns a unique identification for a timer, which can be later used in cancelling a scheduled timer 
            fn(...args)
        }, delay);
    };
}
const search = debounce( () => console.log(`Call API`), 500);
```
- So instead of calling search directly we wrap it in debounce
- debounce returns another function which actually executes immediately when user types

- What is "throttle" 
    This runs every fixed interval, used in scroll tracking - for continuos updates 


----------------------------------------

## Defining Page Structure
MovieSearchPage
 ├── SearchBar
 ├── MovieList
 │     └── MovieCard
 └── Pagination

## IMPORTANT - To keep the code modular, I would break the UI into components 

-------------------------------

## Concepts 
- "Callback props" for Componenet / "EventHandlers" for DOM 
```
<input onChange={handleChange}>
<button onClick={handleClick}>
<SearchBox onSearch={handleSearch}>
```
-----------
```
Parent Component
functin Parent() {
    function handleSearch(text) {
        console.log("Searching:", text);
    }
    return <SearchBox onSearch={handleSearch} />
}
Child Component
function Child({onSearch}) {
    return (
        <input onChange={(e) => onSearch(e.target.value)}
        />
    );
}
```


----------------------------------------

#### The main page component will manage the API data and pagination state, while child components will remain mostly presentational.

- WHAT STATE WE NEED ??
    - searchTerm
    - movies
    - currentPage
    - totalPages
    - loading
    - error

--------------------------------------------------

### When API call happens
- When searchTerm Changes
- When page changes


##### We will use useEffect to trigger API calls wheneer the searchTerm or page changes

```
useEffect(() => {
    fetchMovies(searchTerm, page)
}, [searchTerm, page])
```

When the user types, we update searchTerm, but the API call is delayed using a timer inside useEffect.

User types
   ↓
setSearchTerm()
   ↓
useEffect runs
   ↓
start timer
   ↓
if user types again → clear timer
   ↓
after delay → call API

--------------------------------------------------


“How would you handle large datasets efficiently in React?”
Suppose your movie search returns 10,000 movies.
React will render 10,000 DOM elements.

Problems:
- Slow initial render
- High memory usage
- Laggy scrolling
- Browser repaint cost

Example:
Viewport shows only ~10 movies
But DOM contains 10,000 elements

- The Idea Behind Virtualization - Instead of rendering all items, we render only what the user can see.
- Screen can display 10 items, so we render items - 1-10
- When the user scrolls - Item 11–20, Old items get removed from the DOM.
- All Item is alaready present in RAM, just not in DOM
- Important: When You Actually Need Virtualization, Use it when: > 500

```
const [search, setSearch] = useState("");
useEffect(() => {
  const timer = setTimeout(() => {
    fetchMovies(search);
  }, 300);

  return () => clearTimeout(timer);
}, [search]);
```

- when search changes, before running the new effect, React runs the cleanup function of the previous effect.
- React does this thing below 

Effect Run #1
store cleanup

Effect Run #2
run previous cleanup
store new cleanup

Effect Run #3
run previous cleanup
store new cleanup

----------------------------------------------

# Solution

```
import { useState, useEffect } from "react";

function MovieSearchPage() {
  const [searchTerm, setSearchTerm] = useState("");
  const [movies, setMovies] = useState([]);
  const [page, setPage] = useState(1);
  const [loading, setLoading] = useState(false);

  const fetchMovies = async () => {
    if (!searchTerm) return;

    setLoading(true);

    const res = await fetch(
      `https://www.omdbapi.com/?apikey=YOUR_KEY&s=${searchTerm}&page=${page}`
    );

    const data = await res.json();

    setMovies(data.Search || []);
    setLoading(false);
  };

  useEffect(() => {
    const timer = setTimeout(() => {
      fetchMovies();
    }, 400);

    return () => clearTimeout(timer);
  }, [searchTerm, page]);

  return (
    <div>
      <h1>Movie Search</h1>

      <SearchBar onSearch={setSearchTerm} />

      {loading && <p>Loading...</p>}

      <MovieList movies={movies} />

      <Pagination page={page} setPage={setPage} />
    </div>
  );
}
```


- Search Component
```
function SearchBar({ onSearch }) {
  const handleChange = (e) => {
    onSearch(e.target.value);
  };

  return (
    <input
      type="text"
      placeholder="Search movies..."
      onChange={handleChange}
    />
  );
}
```


------------------------------------------------

```
function MovieList({ movies }) {
  return (
    <div>
      {movies.map((movie) => (
        <MovieCard key={movie.imdbID} movie={movie} />
      ))}
    </div>
  );
}
```


-----------------------------------------


```
function MovieCard({ movie }) {
  return (
    <div>
      <img src={movie.Poster} width="100" />
      <h3>{movie.Title}</h3>
      <p>{movie.Year}</p>

      <a
        href={`https://www.imdb.com/title/${movie.imdbID}`}
        target="_blank"
      >
        View on IMDB
      </a>
    </div>
  );
}
```

Optimised 

```
import React from "react";

const MovieCard = React.memo(function MovieCard({ movie }) {
  return (
    <div>
      <img src={movie.Poster} width="100" />
      <h3>{movie.Title}</h3>
      <p>{movie.Year}</p>

      <a
        href={`https://www.imdb.com/title/${movie.imdbID}`}
        target="_blank"
      >
        View on IMDB
      </a>
    </div>
  );
});

export default MovieCard;
```

-------------------------------------------------

```
function Pagination({ page, setPage }) {
  return (
    <div>
      <button
        disabled={page === 1}
        onClick={() => setPage(page - 1)}
      >
        Prev
      </button>

      <span>Page {page}</span>

      <button onClick={() => setPage(page + 1)}>
        Next
      </button>
    </div>
  );
}
```