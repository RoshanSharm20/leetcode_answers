class ParkingSystem {
public:
    int bigNum,mediumNum,smallNum;
    ParkingSystem(int big, int medium, int small) {
        bigNum=big;
        mediumNum=medium;
        smallNum=small;
    }
    
    bool addCar(int carType) {
        if(carType==1)
        {
            if(bigNum>0)
            {
                bigNum--;
                return true;
            }
            return false;
        }
        if(carType==2)
        {
            if(mediumNum>0)
            {
                mediumNum--;
                return true;
            }
            return false;
        }
        if(carType==3)
        {
            if(smallNum>0)
            {
                smallNum--;
                return true;
            }
            return false;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */