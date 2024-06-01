#ifndef PENADAPTER_H
#define PENADAPTER_H

class PenAdapter
{
public:
    PenAdapter();

    virtual void setColor(int r, int g, int b) = 0;
};

#endif // PENADAPTER_H
