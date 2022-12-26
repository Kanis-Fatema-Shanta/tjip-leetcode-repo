//TC=O(N) 
//MC=O(N)
class Logger {
public:
    unordered_map<string,int> msgs;
    Logger() {
        msgs.clear();
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(msgs.count(message)){
            if(timestamp>=msgs[message])
            {   msgs[message]=timestamp+10;
                return true;
            }
            return false;
        }
        msgs[message]=timestamp+10;
        return true;
    }
};