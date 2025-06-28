#include <iostream>
#include <unordered_map>
#include <string>
#include <ctime>
#include <cstdlib>


using namespace std;


class URLShortener {
private:

    unordered_map<string, string> longToShort; 
    unordered_map<string, string> shortToLong; 


    string baseUrl = "http://short.ly/";

   
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    
    int codeLength = 6;


    string generateCode() {
        string code = "";
        for (int i = 0; i < codeLength; ++i) {
           
            int index = rand() % characters.length();
            code += characters[index];
        }
        return code;
    }

public:

    URLShortener() {
        srand(time(0)); 
    }

    
    string encode(string longUrl) {
        
        if (longToShort.find(longUrl) != longToShort.end()) {
            return baseUrl + longToShort[longUrl];
        }


        string code = generateCode();

       
        while (shortToLong.find(code) != shortToLong.end()) {
            code = generateCode(); 
        }

        
        longToShort[longUrl] = code;
        shortToLong[code] = longUrl;

       
        return baseUrl + code;
    }

    
    string decode(string shortUrl) {
        
        string code = shortUrl.substr(baseUrl.length());

       
        if (shortToLong.find(code) != shortToLong.end()) {
            return shortToLong[code];
        } else {

            return "Error: Short URL not found.";
        }
    }
};


int main() {

    URLShortener shortener;

    
    string longUrl;
    cout << "Enter a long URL to shorten: ";
    getline(cin, longUrl); 


    string shortUrl = shortener.encode(longUrl);
    cout << "Shortened URL: " << shortUrl << endl;

    
    string originalUrl = shortener.decode(shortUrl);
    cout << "Decoded original URL: " << originalUrl << endl;

    return 0;
}
