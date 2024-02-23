/*
COMMON header files:
    iostream->provides definitions for formatted input and output from /to streams;
    fstream->provides definition for formatted input and output from/to file streams;
    iomanip->provides definition for manipulators used to format stream I/O

Comonly used stream classes:
    ios: provides the basic support for formatted and unformatted I/O operations. base class most other classes
    ifstream-> provides for high level input operation on file based streams;
    ofstream-> provides for high level output operations on file based streams
    fstream-> provides for high level output operation on file based streams ; derived from ofstream and ifstream
    stringstream->provides for high level I/O operations on memory based strings derived from "istringstream" and "ostringstream "

NOTE:
    Global objects -initialized before main excutes
    best practice  is to use cerr and clog for error and log message these are global object
    cin nad cout are the instance of an istream and ostream class respectively and these are stream buffer 

Globalstream objects:
    cin: std input stream - by default connected to the std input device. instance of an istream
    cout :std output stream - by default connected to the std output device. instance of an ostream
    cerr- std error stream - by efault connected to the std error device ; instance of ostream, (unbuffered).
    clog std log stream- by default connected to the std log device, instance of ostream (unbuffered)

  
*/
