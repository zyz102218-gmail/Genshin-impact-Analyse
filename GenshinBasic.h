#include <iostream>

class Damage
{
private:
    int BasicAttack;         // Basic Attack Value, Only based on character's level + Weapon's attack value (Without Addition end with %)
    int ConstAttack;         // Attack value from equipment like feather & white value attack in other equipment
    int ElementProfit;       //元素精通 in Chinese... I cannot translate it
    float AttackAdditionR;   // Attack addition, which end with percent(%); Weapon & equipment
    float ElementAddition;   // Element damage addition, with character's own addition & equipment
    float SkillBounce = 100; // Addition based on character's own skill
    float CritProbaility;    // Crit rate, from all
    float CritRate;          // Damage bounce from Crit, basic damage * (1+crit Rate)
    float SpecialRate = 100; // Special Rate, different from characters
    //独立乘区，一般没有该区域，故定义为100%
    float AdditionReactionTimes = 0; //反应系数，额外系数，仅有魔女四件套有
public:
    Damage();
    ~Damage();
    // Basic Setting
    void setSpecialRate(float SpecR);
    void setBasicAttack(int Attack);
    void setConstAttack(int CAttack);
    void setElementProf(int ElementProf);
    void setACKAddition(float ACKAdd);
    void setElementAddition(float ElementAdd);
    void setSkillBounce(float SkillB);
    void setCritProbaility(float CritProb);
    void setCritRate(float CritR);
    void setADDRT(float ADDRT);
    float BasicFromAttack();            // For basic Attack damage
    double BasicBounce();                //倍率计算
    double AdditionBouce();              //增伤计算
    float CritBouce();                  //暴击爆伤计算
    double ReactionBouce(int cases);     //计算反应伤害（系数返回）
    double FullAttackCac(int cases = 5); //整合计算
};