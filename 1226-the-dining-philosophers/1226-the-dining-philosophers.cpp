class Semaphore
{
    private:
        std::mutex m;
        int count;
        std::condition_variable cv;
    public:
        Semaphore()
        {}
        Semaphore(int c): count(c){};
    
    void setCount(int a)
    {
        count=a;
    }
    
    inline void signal()
    {
        std::unique_lock<std::mutex> lock(m);
        count++;
        if(count<=0)
            cv.notify_one();
    }
    
    inline void wait()
    {
        std::unique_lock<std::mutex> lock(m);
        count--;
        if(count<0)
            cv.wait(lock);
    }
        
};
class DiningPhilosophers {
    Semaphore fork[5];
    std:: mutex m;
public:
    
    DiningPhilosophers() 
    {
        for(int i=0;i<5;++i)
            fork[i].setCount(1);
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) 
    {
        //has to be done in a critical section manner
	    {
            std::lock_guard<std::mutex> lock(m);
            fork[(philosopher+1)%5].wait();
            fork[philosopher].wait();
        }
        
        pickLeftFork();
        pickRightFork();
        
        eat();
        
        putLeftFork();
        fork[(philosopher+1)%5].signal();
        putRightFork();
        fork[philosopher].signal();
    }
};