#pragma once

struct Layer
{
    int lvl;
    int type;

    Layer();
    Layer(int lv, int t);

    bool operator==(const Layer &tmp)
    {
        return (lvl == tmp.lvl &&
                type == tmp.type);
    }

    bool operator==(const Layer &tmp) const
    {
        return (lvl == tmp.lvl &&
                type == tmp.type);
    }

    bool operator!=(const Layer &tmp)
    {
        return (lvl != tmp.lvl ||
                type != tmp.type);
    }

    bool operator!=(const Layer &tmp) const
    {
        return (lvl != tmp.lvl ||
                type != tmp.type);
    }
};