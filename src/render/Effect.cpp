#include "Effect.hpp"


Effect::Effect(void)
{
}


Effect::~Effect(void)
{
}

void Effect::setProgram(Program *program) {
    this->program = program;
}

Program *Effect::getProgram() const {
    return this->program;
}