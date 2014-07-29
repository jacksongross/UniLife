//
//  PlayerStatsModel.h
//  UniLife
//
//  Created by Jackson Gross on 29/07/2014.
//
//

#ifndef UniLife_PlayerStatsModel_h
#define UniLife_PlayerStatsModel_h

class PlayerStatsModel
{

private:
    
    int intelligence, stamina, social, money, energy, stress;
    
public:
    
    PlayerStatsModel();
    
    PlayerStatsModel(int intelligence, int stamina, int social, int money, int energy, int stress);
    
    /********************************
                Getters
     *******************************/
    
    int getIntelligence();
    
    int getStamina();
    
    int getSocial();
    
    int getMoney();
    
    int getEnergy();
    
    int getStress();
    
    /********************************
                Setters
     *******************************/
    
    void setIntelligence(int intelligence);
    
    void setStamina(int stamina);
    
    void setSocial(int social);
    
    void setMoney(int money);
    
    void setEnergy(int energy);
    
    void setStress(int stress);
    
    
};

#endif
