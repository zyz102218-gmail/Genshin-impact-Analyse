#include "GenshinBasic.h"
using std::cout;
using std::endl;
void Damage::setBasicAttack(int Attack)
{
    BasicAttack = Attack;
}

void Damage::setConstAttack(int Attack)
{
    ConstAttack = Attack;
}

void Damage::setElementProf(int ElementProf)
{
    ElementProfit = ElementProf;
}

void Damage::setElementAddition(float ElementAdd)
{
    ElementAddition = ElementAdd;
}

void Damage::setACKAddition(float ACKAdd)
{
    AttackAdditionR = ACKAdd;
}

void Damage::setSkillBounce(float SkillB)
{
    SkillBounce = SkillB;
}

void Damage::setCritProbaility(float CritProb)
{
    CritProbaility = CritProb;
}

void Damage::setCritRate(float CritR)
{
    CritRate = CritR;
}

void Damage::setSpecialRate(float SpecR)
{
    SpecialRate = SpecR;
}

void Damage::setADDRT(float ADDRT)
{
    AdditionReactionTimes = ADDRT;
}

float Damage::BasicFromAttack() //仅计算攻击力带来的伤害，相当于参数1
{
    // cout << "BasicATT " << BasicAttack << endl;
    // cout << "ATTAR " << (AttackAdditionR / 100) << endl;
    return (BasicAttack * (1 + (AttackAdditionR / 100)) + ConstAttack);
}

double Damage::BasicBounce() //技能倍率和额外倍率
{
    return (SkillBounce / 100 * SpecialRate / 100);
}

double Damage::AdditionBouce()
{
    return (1 + ElementAddition / 100);
}

float Damage::CritBouce()
{
    return (1 + (CritRate / 100) * (CritProbaility / 100));
}

double Damage::ReactionBouce(int cases)
{
    double ElementProfTimes = (1 + (2.78 * ElementProfit) / (ElementProfit + 1400) + AdditionReactionTimes);
    switch (cases)
    {
    case 1: //蒸发 火打水
        return (1.5 * ElementProfTimes);
    case 2: //蒸发 火打水
        return (2 * ElementProfTimes);
    case 3: //火打冰
        return (2 * ElementProfTimes);
    case 4: //冰打火
        return (1.5 * ElementProfTimes);
    default: //无反应
        return (1);
    }
}

double Damage::FullAttackCac(int cases)
{
    //std::cout << "Onetime: " << BasicFromAttack() * BasicBounce() * AdditionBouce() * CritBouce() * ReactionBouce(cases) << std::endl;
    return BasicFromAttack() * BasicBounce() * AdditionBouce() * CritBouce() * ReactionBouce(cases);
}

Damage::Damage() {}

Damage::~Damage() {}