Review: 

1. A registry is a collection of information about packages.

2. Packages are the source code files (System Verilog, C++, or even cmake files) that we wish to use in our project.

3. Interface library differs slightly from a “normal” library,
because an interface library can consist of code and files that aren’t compiled immediately.
It provides separation of different parts of the code that may or may not be used on a case-by-case basis.

4. Modules which we would like to be exposed for simulation.
