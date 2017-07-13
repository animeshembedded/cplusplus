#include<string>
class Date
{
	public:
	Date() = delete;
	explicit Date(int, std::string, int){}
	private:
	int day;
	char month[4];
	int year;
};
class Device
{
	public:
	Device() {};
	explicit Device(int) { }
	explicit Device(std::string){} 
	explicit Device(Date ){}
	explicit Device(const Device& ) = default;
};
int main()
{
	std::string word("Hello here");
	Date today( 5,"May",2017);// Date today={ 5,"May",2017};

	Device oDevA(100); //Device oDevA = 100;
	Device oDevB('A'); // Device oDevB = 'A'; 
	Device oDevC(true);// Device oDevC = true;
	Device oDevD(1234512344L);// Device oDevD = 1234512344L;
	Device oDevF(word);// Device oDevF = word;

	Device oDevE(oDevA); //Device oDevE = oDevA;	
	Device oDevG(today) ; //Device oDevG = today ;
}	
#if 0
class Date
{
	public:
	Date() = delete;
	Date(int, std::string, int){}
	private:
	int day;
	char month[4];
	int year;
};
class Device
{
	public:
	Device() = default;
	Device(int) { }
	Device(std::string){} 
	Device(Date ){}
};
int main()
{
	std::string word("Hello here");
	Date today={ 5,"May",2017};

	Device oDevA = 100;
	Device oDevB = 'A';
	Device oDevC = true;
	Device oDevD = 1234512344L;
	Device oDevE = oDevA;	
	Device oDevF = word;
	Device oDevG = today ;
}	
#endif
