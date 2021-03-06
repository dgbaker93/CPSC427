#include "stdafx.h"
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <sstream>
#include "..\includes\String_Database.h"
#include "..\includes\DataStore_File.h"
#include "..\includes\Crypto_AES.h"

const int TOTAL_ADDED_PER_THREAD	=20;
const int TOTAL_THREADS				=20;
const std::string ENCRYPT_FILE1 = "Encryptfile1.txt";
const std::string ENCRYPT_FILE2 = "Encryptfile2.txt";

const std::string NO_ENCRYPT_FILE1 = "noEncryptfile1.txt";
const std::string NO_ENCRYPT_FILE2 = "noEncryptfile2.txt";

const int NUMBER_TIMES_TO_ADD_STRING = 20;

//I've provided some hints in the form of comments and commented out code
//use them if you wish

////global database object 
String_Database stringDatabase;
Crypto_AES crytop ("IS IS A BULLSHIT");
DataStore_File dEStore (ENCRYPT_FILE1 , &crytop);
DataStore_File dStore (NO_ENCRYPT_FILE1, NULL);

//will add myString numbTimes to myGlobalCache
void ThreadFunc(int numbTimes, std::string myString) 
{
	for (int i = 0; i < numbTimes; i++)
	{
		stringDatabase.add(myString);
	}
	stringDatabase.save(&dEStore);

	// assert results
	std::cout << ((stringDatabase.getCount(myString) == numbTimes) ? "Pass" : "Fail") << std::endl;
}

bool testSerialization(const std::string &MYFILE1, const std::string &MYFILE2, Crypto *pCrypto){
	//DataStore_File myDataStore_File1(MYFILE1,pCrypto);
	//myGlobalCache.save(&myDataStore_File1);

	//clear cache
	//myGlobalCache.clear();

	//load it
	//myGlobalCache.load(&myDataStore_File1);

	//save to a different file
	//DataStore_File myDataStore_File2(MYFILE2,pCrypto);
	//myGlobalCache.save(&myDataStore_File2);

	//I use my own objects here to compare the files
	return true;
}
int main() {
	
	//for(int i = 0; i < 100; i++) {
	//	std::cout << "" + i << std::endl;
	//	//std::thread t1(ThreadFunc, (rand() % 100 + 10), strcat("test", ""+i));
	//}

	//I created and run a bunch(20) of threads that use ThreadFunc above 
	std::thread t1(ThreadFunc,100,"test1");
	/*std::thread t2(ThreadFunc,100,"test2");
	std::thread t3(ThreadFunc,100,"test3");
	std::thread t4(ThreadFunc,100,"test4");
	std::thread t5(ThreadFunc,100,"test5");
	std::thread t6(ThreadFunc,100,"test6");
	std::thread t7(ThreadFunc,100,"test7");
	std::thread t8(ThreadFunc,100,"test8");
	std::thread t9(ThreadFunc,100,"test9");
	std::thread t10(ThreadFunc,100,"test10");
	std::thread t11(ThreadFunc,100,"test11");
	std::thread t12(ThreadFunc,100,"test12");
	std::thread t13(ThreadFunc,100,"test13");
	std::thread t14(ThreadFunc,100,"test14");
	std::thread t15(ThreadFunc,100,"test15");
	std::thread t16(ThreadFunc,100,"test16");
	std::thread t17(ThreadFunc,100,"test17");
	std::thread t18(ThreadFunc,100,"test18");
	std::thread t19(ThreadFunc,100,"test19");
	std::thread t20(ThreadFunc,100,"test20");
	*/

	t1.join();
	/*t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();
	t11.join();
	t12.join();
	t13.join();
	t14.join();
	t15.join();
	t16.join();
	t17.join();
	t18.join();
	t19.join();
	t20.join();*/

	std::string keep_alive;
	std::cin >> keep_alive;
	////Then I wait for all of them to finish so my program does not crash
 //
	////Then I go through myGlobalCache and make sure that it holds the correct data


	////then I test that serialization works correctly
	////first without encryption, 
	testSerialization(NO_ENCRYPT_FILE1, NO_ENCRYPT_FILE2, 0);


	////then with
	////Crypto_AES myCrypto("I Like Rollos   ");
	////testSerialization(ENCRYPT_FILE1, ENCRYPT_FILE2, &myCrypto);

}