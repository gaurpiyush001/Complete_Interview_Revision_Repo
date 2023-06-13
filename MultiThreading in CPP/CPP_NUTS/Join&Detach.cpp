// In this video we will learn about what is the Use Of join(), detach() and joinable() In Thread In C++ (C++11)

// JOIN NOTES
// 0. Once a thread is started we wait for this thread to finish by calling join() function on thread object.
// 1. Double join will result into program termination.(two times join on same thread Object is not allowed)
//throwing an instance of "std::system_error"
// 2. If needed we should check thread is joinable before joining. ( using joinable() function)

// DETACH NOTES
// 0. This is used to detach newly created thread from the parent thread.
// 1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and 
//    double detach() will result into program termination.
// 2. If we have detached thread and main function is returning then the detached thread execution is suspended.

// NOTES:
// Either join() or detach() should be called on thread object, otherwise during thread object�s destructor it will terminate the program. Because inside destructor it checks if thread is still joinable? if yes then it terminates the program.