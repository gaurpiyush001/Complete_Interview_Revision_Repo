//Q1.)
//Jaoo pehle fta fatt, Question padhke aao -> https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1


//5 approach hai iss question ko krney ki -> By graph O(N^2), By Recursion O(N), By Stack O(N), By two pointer Approach(), 
//by brute Force TC O(N). 

//Approach kya hai?? Brute Force --> har ek row ko check kro pehle if there is a row with all zero(mtlb vo kissi ko nhi jaanta), then it is possible candidate for celebrity, To ensure it -> now check its coloumn if there are all 1's present iun coloumn(except itself (i,i))-->mtlb usse sb jaantey haii, Then finally we can say celebrity is present in the party
//T.C--> O(N^2)

//Optimized Aprroach --> T.C -> O(N)
//What is the intution to use a data structure in this problem?? 

//Go to editorial --> https://www.codingninjas.com/blog/2021/09/22/celebrity-problem/

//----------------------------------------------------------------//

//Question 2.) https://practice.geeksforgeeks.org/problems/max-rectangle/1/