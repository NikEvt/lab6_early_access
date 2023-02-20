#include "lib/parser.h"


int main(int, char**) {
    omfl::parser prs;
    omfl::argument a("1");
    omfl::argument b("2");
    a = b;
    prs.primary_section.push_back(a);
    return 0;
}
