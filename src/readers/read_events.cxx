#include <iostream>
#include "UnigenEventCandidate.h"
#include "UnigenReader.h"

int main(int argc, char *argv[])
{
    UnigenReader reader("/home/jedkol/Downloads/UniGen/bin","events",1);
    UnigenEventCandidate event;

    reader.InitReader();
    while (reader.GetNextEvent(event))
    {
        /* code */
    }
    reader.CloseReader();

    return 0;
}