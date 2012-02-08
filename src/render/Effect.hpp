
#ifndef EFFECT_HPP
#define	EFFECT_HPP

#include "Program.hpp"

class Effect
{
public:
    Effect(void);
    ~Effect(void);
    void setProgram(Program *program);
    Program *getProgram() const;
private:
    Program *program;
};

#endif /* EFFECT_HPP */