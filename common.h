#ifndef COMMON_H
#define COMMON_H

extern int debug;

#define dbg(str) if(debug) std::cout <<str << std::endl

// mnemonics classification
enum mnemonics {
    JMP,
    ADD,
    SUB
};

#endif // COMMON_H
