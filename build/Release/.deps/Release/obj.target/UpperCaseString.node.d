cmd_Release/obj.target/UpperCaseString.node := g++ -o Release/obj.target/UpperCaseString.node -shared -pthread -rdynamic -m64  -Wl,-soname=UpperCaseString.node -Wl,--start-group Release/obj.target/UpperCaseString//src/UpperCaseString.o -Wl,--end-group 
