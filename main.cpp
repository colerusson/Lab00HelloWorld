#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

int main(int argc, char* argv[])
{
    VS_MEM_CHECK                        // enable VS check for memory leaks

        if (argc < 3) return 1;
    ifstream in = ifstream(argv[1]);    // open argv[1] for input
    if (!in) return 1;
    ofstream out = ofstream(argv[2]);   // open argv[2] for output
    if (!out) return 2;

    // read input file lines and send to output file
    for (string line; getline(in, line);)
    {
        out << line << endl;
    }

    return 0;
}
