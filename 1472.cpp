class BrowserHistory
{
public:
    vector<string> browser;
    int pos = 0;
    BrowserHistory(string homepage)
    {
        browser.push_back(homepage);
    }

    void visit(string url)
    {
        pos++;                         // if your visiting a new webpage then it means your position is increasing by one from the current position
        if (pos <= browser.size() - 1) // if the new position is in between the already existing webpage array then by inserting a new page will erase the contents that were already
        {
            browser[pos] = url;
            browser.resize(pos + 1); // and new size will be reduced to pos+1
        }
        else
            browser.push_back(url); // else if the page is added at the end of the list then just add it end of the list
    }

    string back(int steps)
    {
        pos -= steps;
        if (pos < 0)
            pos = 0;
        return browser[pos];
    }

    string forward(int steps)
    {
        pos += steps;
        if (pos > browser.size() - 1)
            pos = browser.size() - 1;
        return browser[pos];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */