// ============================================================================ 
// main.cpp
// ~~~~~~~~
// author: James Droste <james@droste.im> & hqn
// Description: UBHeap CLI Client
// - new heapname = [list of integers separated by space]
// - top heapname
// - pop heapname
// - push heapname [an integer]
// - print heapname
// - exit
// ============================================================================ 
#include <cstdlib>   // for exit(0)
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <stdexcept>

#include "UBHeap.h"
#include "error_handling.h"
#include "term_control.h"

using namespace std; // BAD PRACTICE

void prompt();
typedef void (*cmd_t)(istringstream&);
void bye(istringstream&);
void new_cmd(istringstream&);
void top_cmd(istringstream&);
void pop_cmd(istringstream&);
void push_cmd(istringstream&);
void print_cmd(istringstream&);

map<string, UBHeap> heap_table; // our "symbol table"

const string usage_msg = "UBHeap: build and test a Heap data structure";

int main() 
{
    map<string,cmd_t> cmd_map;
    cmd_map["exit"]   = &bye;
    cmd_map["bye"]    = &bye;
    cmd_map["quit"]   = &bye;
    cmd_map["new"]    = &new_cmd;
    cmd_map["top"]    = &top_cmd;
    cmd_map["pop"]    = &pop_cmd;
    cmd_map["push"]   = &push_cmd;
    cmd_map["print"]  = &print_cmd;

    cout << term_cc(YELLOW) << usage_msg << endl;

    istringstream iss;
    string cmd, line;
    while (cin) {
        prompt(); 
        getline(cin, line);
        iss.clear();
        iss.str(line);
        if (!(iss >> cmd))
            continue;

        if (cmd_map.find(cmd) != cmd_map.end()) {
            try {
                cmd_map[cmd](iss);
            } catch (runtime_error &e) {
                error_return(e.what());
            }
        } else {
            error_return("Unknown command");
        }
    }
    return 0;
}

void bye(istringstream& iss)
{
    exit(0);
}

void new_cmd(istringstream& iss)
{
    string list_name;
    char a;
    int member;
    if (!(iss >> list_name) || !(iss >> a) || a != '=') {
        throw runtime_error("Syntax: new heapname = [list of integers separated by space]");
    }

    vector<int> list;
    while (iss >> member)
        list.push_back(member);

    UBHeap ubheap(list);

    heap_table[list_name] = ubheap; // assignment operator called!
}

void top_cmd(istringstream& iss)
{
    string name;
    if (!(iss >> name))
        throw runtime_error("Syntax: top heapname");
    if (heap_table.find(name) == heap_table.end())
        throw runtime_error(string("Heap ") + name + " not found");
    cout << term_cc(YELLOW) << heap_table[name].top() 
         << endl << term_cc();
}

void pop_cmd(istringstream& iss)
{
    string name;
    if (!(iss >> name))
        throw runtime_error("Syntax: pop heapname");
    if (heap_table.find(name) == heap_table.end())
        throw runtime_error(string("Heap ") + name + " not found");
    heap_table[name].pop();
}

void push_cmd(istringstream& iss)
{
    int element;
    string name, tmp;
    if (!(iss >> name) || !(iss >> element))
        throw runtime_error("Syntax: push heapname [an integer]");
    if (heap_table.find(name) == heap_table.end())
        throw runtime_error(string("Heap ") + name + " not found");
    heap_table[name].push(element);
}

void print_cmd(istringstream& iss)
{
    string name;
    if (!(iss >> name))
        throw runtime_error("Syntax: print heapname");
    if (heap_table.find(name) == heap_table.end())
        throw runtime_error(string("Heap ") + name + " not found");

    cout << term_cc(YELLOW) << heap_table[name].toString() 
         << endl << term_cc();
}

void prompt() 
{
    cout << term_cc(BLUE) << "> " << term_cc() << flush;
}