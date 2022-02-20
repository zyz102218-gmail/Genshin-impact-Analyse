#include <iostream>
#include "GenshinBasic.h"
#include <vector>
#include <numeric>
using namespace std;

double AttRate[7] = {56.3, 56.3, 108.0, 140.4, 73.3, 73.3, 167.2};
void BasicSettingXiaogong(Damage *C)
{
    C->setBasicAttack(323 + 608);
    C->setConstAttack(311 + 100);
    C->setACKAddition(46.6 + 40.3);
    C->setElementAddition(46.6);
    // C->setSkillBounce();
    C->setCritProbaility(60);
    C->setCritRate(300);
    C->setSpecialRate(155.8); //技能8级
    C->setElementProf(240);
}
int main()
{
    Damage *XiaogongLiuxing = new Damage;
    Damage *XiaogongZhuiyi = new Damage;
    Damage *AXiaogong[2] = {XiaogongLiuxing, XiaogongZhuiyi};
    for (Damage *C : AXiaogong)
    {
        BasicSettingXiaogong(C);
    }
    XiaogongLiuxing->setSpecialRate(195.8);
    XiaogongZhuiyi->setSpecialRate(205.8);

    double SumDamage[2];
    int i = 0;
    for (Damage *C : AXiaogong)
    {
        vector<double> FullDamage;
        for (double ATTR : AttRate)
        {
            C->setSkillBounce(ATTR);
            FullDamage.push_back(C->FullAttackCac());
        }
        SumDamage[i] = 3 * accumulate(FullDamage.begin(), FullDamage.end(), 0);
        i++;
    }
    cout << "Normal Attack Damage sum ans:" << endl;
    for (double sum : SumDamage)
    {
        cout << "SumDamage: " << sum << endl;
    }
    XiaogongLiuxing->setSpecialRate(100); //流星套假定护盾仍在，大招充满，大招无特殊倍率乘区
    XiaogongLiuxing->setSkillBounce(204);
    SumDamage[0] += XiaogongLiuxing->FullAttackCac();
    XiaogongLiuxing->setSkillBounce(195); //火光爆炸
    SumDamage[0] += 5 * XiaogongLiuxing->FullAttackCac();
    cout << "Full Liuxing: " << SumDamage[0] << endl;
    return 0;
}