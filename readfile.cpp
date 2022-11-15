//C++ program to read file in and output the occurence of words as key value pair by STEPHENSONENG

#include <iostream>
#include<fstream>
#include<map>
#include<string>
#include<thread> 
#include<sstream>


class File{

public:
	
	static void read(std::ifstream& f) { 
		std::map<std::string, int> wordMap;                         
		try {                                                      
			//file open succesfully check  
			 
			if (f.is_open()) {
				using namespace std;
				string line;
				
				while (getline(f, line)) {
					cout << line << endl;
					std::stringstream s(line);
					string word;
					char delims[] = "" ",;:";
					
					while (s>>word,delims) 
						wordMap[word]++;
			
					cout << "counting occurences of words in file \n";
					std::this_thread::sleep_for(std::chrono::seconds(2));
					for (auto& [key, value] : wordMap)                            //strucuture binding (c++17) to traverse map and get the 
						cout << key << " " << "-" << " " << value << endl;       //key value pair
					

					f.close();
					
				}
				
			} throw 353;    //attempt to open file failed    

		}
		catch (...) { std::cerr << "ERROR:" << " " << "Can't open file" << "\n"; }//output of error message

	}
};
int main(){ 
	std::cout << "Enter a filename example format of"
			<< std::endl 
			<< "filename.txt" << "\n";
	std::string fileString = "";
    std::cin >> fileString;
    std::ifstream wordFile;
    wordFile.open(fileString);
    File::read(wordFile);
	
    return 0;
    std::cin.get();
}

