This is the template for the first assignment. 

# Tips on checking compilation

If you want to compile your code in the same way the demonstrators will compile it to check it, you can just write "make" in the console. 
This will use a the combination of the `make` command with a `Makefile` file that you will see in the same folder. In this case, doing this which in this case will run the following command:

`g++-11 assignment-1.cpp -o assignment-1.o -std=gnu++17`

The std=gnu++17 makes sure that the compiler you're using locally (which you should have installed following the instructions on the Quickstart guide on Blackboard/Git) picks up the same version of the C++ standards as the computers in the lab. 

This command will produce the following file in the same directory you're running on:

`g++-11 assignment-1.cpp -o assignment-1.o -std=gnu++17`

Which you can then execute in a terminal using: 

`./assignment-1.o`

You can find out more about Makefiles [here](https://www.gnu.org/software/make/manual/html_node/Introduction.html) or [in this simple starter guide](https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/) but we won't cover these in the course. 
