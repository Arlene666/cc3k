#ifndef _BD_H_
#define _BD_H_

class BD : public Potion {
    public:
    BD();
    void used(Shade &p) override;
    void used(Drow &p) override;
    void used(Vampire &p) override;
    void used(Troll &p) override;
    void used(Goblin &p) override;
};


#endif
