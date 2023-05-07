#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <conio.h>
#include <algorithm>
using namespace std;
class hashtable;
class trie;
void menu(hashtable&, trie&);

class listnode
{
	listnode* next;
	string filename;
public:
	listnode* getnext()
	{
		return next;
	}
	string getfilename()
	{
		return filename;
	}
	void setnext(listnode* node)
	{
		this->next = node;
	}
	void setfilename(string file)
	{
		this->filename = file;
	}
};
class list
{
	listnode* head;
public:
	list()
	{
		head = NULL;
	}
	listnode* gethead()
	{
		return head;
	}
	void insert(string file)
	{
		listnode* newnode = new listnode;
		newnode->setfilename(file);
		newnode->setnext(NULL);
		if (head == NULL)
		{
			head = newnode;
		}
		else
		{
			listnode* trav;
			trav = head;
			while (trav->getnext() != NULL)
			{
				trav = trav->getnext();
			}
			trav->setnext(newnode);
		}
	}
	void printlist(listnode* h, string word, int choice)
	{
		
		listnode* trav;
		trav = h;
		while (trav != NULL)
		{
			cout << "\n\t\tFILE: " << trav->getfilename() << "\n\n";;
			if (choice == 1)
				openfile(trav->getfilename(), word);
			trav = trav->getnext();
		}
	}
	void printlist(string word, string word2, int choice)
	{
		listnode* trav;
		trav = head;
		while (trav != NULL)
		{
			cout << "\n\t\tFILE: " << trav->getfilename() << "\n\n";
			if (choice == 1)
				openfile2(trav->getfilename(), word, word2);
			trav = trav->getnext();
		}
	}
	listnode* and_search(listnode* h1, listnode* h2)
	{
		listnode* trav1;
		listnode* trav2;
		trav1 = h1;
		trav2 = h2;
		if (h1 == NULL || h2 == NULL)
			return NULL;
		while (trav1 != NULL)
		{
			//cout << 3333 << endl;
			trav2 = h2;
			while (trav2 != NULL)
			{
				//cout << 1111 << endl;
				if (trav1->getfilename() == trav2->getfilename())
				{
					/*cout << 22222 << endl;*/
					insert(trav1->getfilename());
				}
				trav2 = trav2->getnext();
			}
			trav1 = trav1->getnext();
		}
	}
	void or_search(listnode* h1, listnode* h2)
	{
		listnode* trav;

		int i = 0;
		if (h1 == NULL)
		{
			trav = h2;
			while (trav != NULL)
			{
				insert(trav->getfilename());
				trav = trav->getnext();
			}
		}
		else if (h2 == NULL)
		{
			trav = h1;
			while (trav != NULL)
			{
				insert(trav->getfilename());
				trav = trav->getnext();
			}
		}
		else
		{
			trav = h1;
			while (trav != NULL)
			{
				if (i == 2)
					break;
				insert(trav->getfilename());
				if (trav->getnext() == NULL)
				{
					trav = h2;
					i++;
					continue;
				}

				trav = trav->getnext();
			}
		}
	}
		void openfile2(string filetoopen, string word, string word2)
	{
		ofstream ofile;
		ifstream fin;
		string s = "C:/Users/kk/Desktop/prr/Project1/";
		string str = s + filetoopen;
		 fin.open(filetoopen,ios::in|ios::binary);
		{
			if (!fin)
			{
				//cout << "file not found" << endl;
				/*file = "C://Users//HHH//Desktop//MUBIN//my programs//DATA STRUCTURES//project//my project//search engine in vs//" + file;
				cout << file.c_str() << endl;
				ofile.open(file.c_str());
				ofile.close();*/
			}
			else
			{
				int i = 0;
				string word1;
				while (fin >> word1)
				{
					if (word1 == word || word1 == word2)
					{
						cout << "(" << word1 << ")";
					}
					else
					{
						cout << word1;
					}
					cout << " ";
				}
				cout << "\n\n";
				fin.close();
				/*cout << "\n\n\n";*/
			}
		}
	}
	void openfile(string filetoopen, string word)
	{
		ofstream ofile;
		ifstream fin;
		string s = "C:/Users/kk/Desktop/prr/Project1/";
		string str = s + filetoopen;
		 fin.open(filetoopen,ios::in|ios::binary);
		{
			if (!fin)
			{
				//cout << "file not found" << endl;
				/*file = "C://Users//HHH//Desktop//MUBIN//my programs//DATA STRUCTURES//project//my project//search engine in vs//" + file;
				cout << file.c_str() << endl;
				ofile.open(file.c_str());
				ofile.close();*/
			}
			else
			{
				int i = 0;
				string word1;
				while (fin >> word1)
				{
					if (word1 == word)
					{
						cout << "(" << word1 << ")";
					}
					else
					{
						cout << word1;
					}
					cout << " ";
				}
				cout << "\n\n";
				fin.close();
				/*cout << "\n\n\n";*/
			}
		}
	}
	void removeduplicates()
	{
		listnode* curr = head;
		listnode* before = NULL;
		listnode* after = NULL;
		listnode* dup = NULL;
		while (curr->getnext() != NULL)
		{
			before = curr;
			after = before->getnext();
			while (after->getnext() != NULL)
			{
				//cout << "\ncurr= " << curr->getfilename() << "\nbfore= " << before->getfilename() << "\nafter= " << after->getfilename() << endl;

				if (curr->getfilename() == after->getfilename())
				{
					dup = after;
					before->setnext(after->getnext());
					after = after->getnext();
					delete(dup);
				}
				else
				{
					before = after;
					after = after->getnext();
				}

			}
			if (curr->getfilename() == after->getfilename())
			{
				before->setnext(nullptr);
				continue;
			}
			curr = curr->getnext();
		}
	}
};

class hashtable
{
	list l1[60000];
	int key;
	vector<pair<int, listnode*>>table;
	int collision[60000];
public:
	hashtable()
	{
		for (int i = 0; i < 60000; i++)
		{
			table.push_back(make_pair(0, nullptr));
		}
	}
	int setkey(string word, string file)
	{
		/*int ret;*/
		int keyval = 0;
		keyval = findkey(word);
		key = keyval % 60000;
		checkcollision(key, 1, keyval, file, word);
//		cout<<key<<" ";

		//cout << endl << word << endl;
		return keyval;
	}
	int findkey(string word)
	{

		int keyval = 0;
		int sum = 0;
		int constant = 2;
		int i = 0;
		while (word[i] != '\0')
		{


			sum = int(word[i]);
//			cout<<sum<<"\n";
			sum = sum * pow(constant, i+1);//cout << endl <<"sum= "<< sum << endl;
			keyval = keyval + sum;//cout << endl <<"keyval= "<< keyval << endl;
			i++;
		}
		return keyval;
	}

	int checkcollision(int key1, int i, int keyval, string file, string word)
	{
		if (table[key1].first != 0 && table[key1].first != keyval)
		{
			int key2;
			collision[key1]++;
			if (collision[key1] > 10)
				cout << "\nALLERT\n";
			key2 = key1 + pow(i, 3);
			/*cout << endl <<"key= "<< key << endl;*/
			key2 = key2 % 60000;
			checkcollision(key2, i + 1, keyval, file, word);
		}
		else if (table[key1].first == keyval)
		{
			l1[key1].insert(file);
			l1[key1].removeduplicates();
			//l1[key].printlist();
		 
		}
		else
		{

			table[key1].first = keyval;
			l1[key1].insert(file);
			table[key1].second = l1[key].gethead();
			

			return key1;
		}
	}
	int checkcollisionforsearch(int key1, int i, int keyval)
	{
		if (table[key1].first != 0 && table[key1].first != keyval)
		{
			int key2;
			key2 = key1 + pow(i, 3);
			/*cout << endl <<"key= "<< key << endl;*/
			key2 = key2 % 60000;
			checkcollisionforsearch(key2, i + 1, keyval);
		}
		else if (table[key1].first == keyval)
		{
			return key1;
		}
		else if (table[key1].first == 0)
		{
			return -1;
		}
	}
	void printtable()
	{
		for (int i = 660; i <= 670; i++)
		{
			cout << i << "\t" << table[i].first << "\t" << collision[i] << "\t" << table[i].second << "\t";
			//l1[i].printlist(table[i].second);
			cout << endl;
		}

	}
	void readallfiles()
	{
		ofstream ofile;
		ifstream fin;
		string s = "C:/Users/kk/Desktop/prr/Project1/text";
		for (int i = 1; i < 200; i++)
		{
			string str = to_string(i); string file = "text" + str;
			file = file + ".txt";
			str = s + str + ".txt";


			 fin.open(file,ios::in|ios::binary);
			{
				if (!fin)
				{
					//cout << "file " << i << endl;
					file = "C:/Users/kk/Desktop/prr/Project1//" + file;
					cout << file.c_str() << endl;
					ofile.open(file.c_str());
					ofile.close();
				}
				fin.close();
			}
		}
	}
	int addnewfile(char* data)
	{
		ifstream fin;
		int nofile;
		string s = "C:/Users/kk/Desktop/prr/Project1/text (";
		for (int i = 1; i < 200; i++)
		{
			string str = to_string(i); string file = "text (" + str + ")";
			file = file + ".txt";
			str = s + str + ").txt";

			//cout << file << endl;
			//cout << str << endl;
			 fin.open(file,ios::in|ios::binary);
			{
				if (!fin)
				{
					cout << "\n\t\tYOUR FILE HAS BEEN CREATED BY THE NAME: text (" << i << ")\n\t\t";
					nofile = i;

					fin.close();
					break;
				}
				fin.close();

			}//cout << endl << "i= " << i << endl << sizeoftable << endl;
		}
		string str = to_string(nofile); string file = "text (" + str + ")";
		file = file + ".txt";
		str = s + str + ").txt";
		fflush(stdin);
		ofstream fout;
		 fout.open(file,ios::app|ios::binary);
		{
			/*char data[100];
			cin.getline(data, 100);*/
			fout << data;

		}
		fout.close();
		storenewfile(str, file);
		//printtable();
		return nofile;

	}
	void storenewfile(string str, string file)
	{
		//cout << 1111;
		ifstream fin;
		string word;
		 fin.open(file,ios::in|ios::binary);
		{
			while (fin >> word)
			{
				////cout << 222<<endl;
				setkey(word, file);
			}
			fin.close();
		}
	}
	int writepreviousfiles()
	{
		
		char x = 221;
		int sizeoftable = 0;
		ifstream fin;
		//cout << "\n\t\t\t";
	
		for (int i = 1; i < 200; i++)
		{
			if (i % 5 == 0)
				cout << x;
			string str = to_string(i); string file = "text (" + str + ")";
			file = file + ".txt";
			

			//cout << file << endl;
			//cout << str << endl;
			fin.open(file,ios::in|ios::binary);
			{
				if (!fin)
				{
					//cout << "file " << i << endl;
					/*file = "C://Users//HHH//Desktop//MUBIN//my programs//DATA STRUCTURES//project//my project//search engine in vs//" + file;
					cout << file.c_str() << endl;
					ofile.open(file.c_str());
					ofile.close();*/
					fin.close();
				}
				else
				{
					int i = 0;
					string word="";
					while (fin >> word)
					{
//						cout<<word;
						setkey(word, file);

					
						i++;
						sizeoftable++;
					
					}

					fin.close();
					/*cout << "\n\n\n";*/
				}
			}//cout << endl << "i= " << i << endl << sizeoftable << endl;
		}
		//printtable();

		return sizeoftable;
	}
	int sizefiles()
	{

		int sizeoftable = 0;
		ifstream fin;
		string s = "C:/Users/kk/Desktop/prr/Project1/text (";
		for (int i = 1; i < 200; i++)
		{
			string str = to_string(i); string file = "text (" + str + ")";
			file = file + ".txt";
			str = s + str + ").txt";

			//cout << file << endl;
			//cout << str << endl;
			 fin.open(file,ios::in|ios::binary);
			{
				if (!fin)
				{
					//cout << "file " << i << endl;
					/*file = "C://Users//HHH//Desktop//MUBIN//my programs//DATA STRUCTURES//project//my project//search engine in vs//" + file;
					cout << file.c_str() << endl;
					ofile.open(file.c_str());
					ofile.close();*/
				}
				else
				{
					int i = 0;
					string word;
					while (fin >> word)
					{

						sizeoftable++;
					}

					fin.close();
					/*cout << "\n\n\n";*/
				}
			}
		}
		//printtable();
		return sizeoftable;
	}
	listnode* searchword(string tofind, int choice)
	{
		int keyval = findkey(tofind);
		key = keyval % 60000;

		key = checkcollisionforsearch(key, 1, keyval);
		//cout << endl << key << endl;
		if (key == -1)
		{
			if (choice == 1)
			{
				cout << "\n\t\tWORD NOT PRESENT\n\t\tNO FILES FOUND";
			}

			return NULL;
		}
		else
		{
			//
			
				cout << "\n\t\tWORD PRESENT\n\t\t";
				cout << "FILES\n\t\t";
				l1[key].printlist(table[key].second, tofind, 0);
			
				cout << "\nDO YOU WANT TO OPEN THESE FILES TO SEE WHERE THE WORD IS PRESENT\n1. YES\n2. NO\n";
				int ch;
				cin >> ch;
				if (ch == 1)
					l1[key].printlist(table[key].second, tofind, 1);
			

		}
		return table[key].second;

	}


};
class trienode
{
	bool isword;
	trienode* nodes[26];
public:

	trienode()
	{
		isword = false;
		for (int i = 0; i < 26; i++)
		{
			nodes[i] = nullptr;
		}
	}
	bool getisword(){
		return isword;
	}
	friend class trie;
};
class trie
{
	trienode* root;
public:
	trie()
	{
		root = NULL;
	}
	void insert(string word)
	{

		trienode* temp;
		if (root == NULL)
		{
			root = new trienode;
		}
		temp = root;

		int key = 0;
		for (int i = 0; i < word.size(); i++)
		{
			key = int(word[i]) - int('a');
			
			//cout << endl << key << endl;
			if (temp->nodes[key] == NULL)
			{
				//cout << "\nkey inserted\n";
				temp->nodes[key] = new trienode;
				temp = temp->nodes[key];
			}
			else
			{
				temp = temp->nodes[key];
			}

		}
		//cout << "\n1\n";
		temp->isword = true;
	}
		bool search(string word)
	{
		//cout << "\n1\n";
		string newword;
		vector<string> wordsfound;
		queue<pair<string, trienode*>> q;
		int key = 0;
		trienode* temp;
		temp = root;
		bool isTerminal;
		if (root == NULL)
		{
			return 0;
		}
		else
		{
			for (int i = 0; i < word.size(); i++)
			{
				key = int(word[i]) - int('a');
				
				if (temp->nodes[key] != NULL)
				{
					//cout << "\nfoundc\n";
					temp = temp->nodes[key];
					
				
				}

			}
			isTerminal=temp->getisword();
			q.push(make_pair(word, temp));
//			cout<< q.front().first<<"\n\n\n";
			while (!q.empty())
			{
				newword = q.front().first;
			
				temp = q.front().second;
			
				q.pop();
				if (temp->isword == true)
				{
					//cout << "\nyes\n";
					wordsfound.push_back(newword);
				}

				for (int i = 0; i < 26; i++)
				{
					if (temp->nodes[i] != NULL)
					{
						//cout << "\ni= " << i << endl;
						q.push(make_pair(newword + char(i + int('a')), temp->nodes[i]));
						//cout << endl << "newword= "<< newword << endl;
					}
				}


			}
			for (int j = 0; j < wordsfound.size() % 20; j++)
			{
				cout << endl << "\t\t" << wordsfound[j] << endl;
			}
		}
		return isTerminal;
	}
	int writepreviousfiles()
	{
		char x = 219;
		//hashtable h1;
		//int sizeoftable = 0;
		ifstream fin;
		cout << "\n\t\tPLEASE WAIT WHILE THE SEARCH ENGINE IS LOADING\n\t\t";
		string s = "C:/Users/kk/Desktop/prr/Project1/text (";
		for (int i = 1; i < 200; i++)
		{
		
			string str = to_string(i);
			string file = "text (" + str + ")";
			file = file + ".txt";
			str = s + str + ").txt";

			//cout << file << endl;
			//cout << str << endl;
		fin.open(file,ios::in|ios::binary);
			{
				if (!fin)
				{
			
				}
				else
				{
					/*int i = 0;*/
					string word = " ";
					while (fin >> word)
					{
						bool flag = true;
						/*cout << word<<endl;*/

						for (int j = 0; j < word.size(); j++)
						{
							if (word[j] < 'a' || word[j] > 'z')
							{
								flag = false;
							
							}
					


						}
				
						if (flag)
						{
							transform(word.begin(), word.end(), word.begin(), ::tolower);
							/*cout << 1 << endl;*/
							/*cout <<"inserted "<< word << endl;*/
							insert(word);
						}


			
					}

					fin.close();
					/*cout << "\n\n\n";*/
				}
			}
		}
	
		return 0;
	}
	void addnewfile(int i)
	{
		ifstream fin;
		string s = "C:/Users/kk/Desktop/prr/Project1/text (";
		string str = to_string(i); string file = "text (" + str + ")";
		file = file + ".txt";
		str = s + str + ").txt";
		 fin.open(file,ios::in|ios::binary);
		{
			string word = " ";
			while (fin >> word)
			{
				bool flag = true;
				/*cout << word<<endl;*/

				for (int j = 0; j < word.size(); j++)
				{
					if (word[j] < 'a' || word[j] > 'z')
					{
						flag = false;
						goto t;
					}


				}
			t:
				if (flag)
				{
					//transform(word.begin(), word.end(), word.begin(), ::tolower);
					/*cout << 1 << endl;*/
					/*cout <<"inserted "<< word << endl;*/
					insert(word);
				}


				//cout << endl << h1.setkey(word) << endl;
				/*i++;*/
				//sizeoftable++;
			}

			fin.close();
		}
	}
};
class user
{
public:
	void search(hashtable& h1, trie& t1)
	{
		listnode* n1 = new listnode;
		listnode* n2 = new listnode;
	agai:
		char t;
		bool temp1=0,temp2=0;
		cout<<temp1<<endl<<temp2;
		string s, d;
		int choice;

		cout << "\n\t\tWHICH KIND OF SEARCH DO YOU WANT TO PERFORM?\n\t\t1.SIMPLE SEARCH\n\t\t2.SEARCH WITH AND OPERATOR\n\t\t3.SEARCH WITH OR OPERATOR\n\t\t4.RETURN TO MAIN\n\t\t";
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			cout << "\n\t\tENTER THE WORD YOU WANT TO SEARCH\n\t\t";
			while (1)
			{

			
				t = _getch();

				if ((t >= 'a' && t <= 'z') || t == '\b' || t == 13)
				{
					if (t == 13)
						break;
					system("cls");
					cout << "\n\t\tENTER THE WORD YOU WANT TO SEARCH\n\t\t";
					if (t == '\b')
					{
						if (s != "")
							s.pop_back();
						else
							continue;
					}
					else
					{
						s.push_back(t);
					}
					cout << s << "\n\t\t";
				
					if (s != "")
					{	
						cout << "SUUGESTED WORDS\n";
						temp1=t1.search(s);
					}

				}
				else
					continue;

			}
			if (s != "")
			{
				system("cls");
				cout << "\n\t\tYOU SEARCHED FOR: " << s << "\n\t\t";
				//cout << h1.findkey(d);
				n1 = h1.searchword(s, 1);
			}
			else
			{
				cout << "\n\t\tNO INPUT\n\t\t";
				system("cls");
				goto agai;
			}
		}
		else if (choice == 3)
		{
			cout << "\n\t\tENTER THE WORD YOU WANT TO SEARCH\n\t\t";
			while (1)
			{


				t = _getch();
				if ((t >= 'a' && t <= 'z') || t == '\b' || t == 13)
				{
					if (t == 13)
						break;
					system("cls");
					cout << "\n\t\tENTER THE WORD YOU WANT TO SEARCH\n\t\t";
					if (t == '\b')
					{
						if (s != "")
							s.pop_back();
						else
							continue;
					}

					else
					{
						s.push_back(t);
					}

					cout << s << "\n\t\t";
					if (s != "")
					{
						cout << "SUUGESTED WORDS\n";
						temp1=t1.search(s);
					}

				}
				else
					continue;

			}
			fflush(stdin);
			system("cls");
			cout << "\n\t\tENTER THE SECOND WORD YOU WANT TO SEARCH\n\t\t";
			while (1)
			{


				t = _getch();
				if ((t >= 'a' && t <= 'z') || t == '\b' || t == 13)
				{
					if (t == 13)
						break;
					system("cls");
					cout << "\n\t\tENTER THE WORD YOU WANT TO SEARCH\n\t\t";
					if (t == '\b')
					{
						if (s != "")
							s.pop_back();
						else
							continue;
					}
					else
					{
						d.push_back(t);
					}

					cout << d << "\n\t\t";
					if (d != "")
					{
						cout << "SUUGESTED WORDS\n";
						temp2=t1.search(s);
					}

				}
				else
					continue;

			}

			list* l2 = new list;
			if (s != "" && d != "")
			{
				system("cls");
				cout << "\n\t\tYOU SEARCHED FOR: " << s << " OR(||) " << d << "\n\t\t";
				//cout << h1.findkey(d);
				n1 = h1.searchword(s, 0);
				n2 = h1.searchword(d, 0);
				l2->or_search(n1, n2);
				cout << "\n";
				l2->removeduplicates();
				l2->printlist(s, d, 0);
				cout << "\nDO YOU WANT TO OPEN THESE FILES TO SEE WHERE THE WORD IS PRESENT\n1. YES\n2. NO\n";
				int ch;
				cin >> ch;
				if (ch == 1)
				{
					system("cls");
					l2->printlist(s, d, 1);
				}


			}
			else
			{
				cout << "\n\t\tNO INPUT\n\t\t";
				goto agai;
			}
			delete l2;
		}
		else if (choice == 2)
		{

			cout << "\n\t\tENTER THE FIRST WORD YOU WANT TO SEARCH\n\t\t";
			while (1)
			{


				t = _getch();
				if ((t >= 'a' && t <= 'z') || t == '\b' || t == 13)
				{
					if (t == 13){
						temp1=t1.search(s);
						system("cls");
						break;
					}
					system("cls");
					cout << "\n\t\tENTER THE First WORD YOU WANT TO SEARCH\n\t\t";
					if (t == '\b')
					{
						if (s != "")
							s.pop_back();
						else
							continue;
					}
					else
					{
						s.push_back(t);
					}

					cout << s << "\n\t\t";
					if (s != "")
					{
						cout << "SUUGESTED WORDS\n";
					temp1=t1.search(s);
					}

				}
				else
					continue;

			}

			system("cls");
			cout << "\n\t\tENTER THE SECOND WORD YOU WANT TO SEARCH\n\t\t";
			while (1)
			{

				
				t = _getch();
				if ((t >= 'a' && t <= 'z') || t == '\b' || t == 13)
				{
					if (t == 13){
						temp2=t1.search(d);
						system("cls");
						break;
					}	
					system("cls");
					cout << "\n\t\tENTER THE  SECOND WORD YOU WANT TO SEARCH\n\t\t";
					if (t == '\b')
					{
						if (d != "")
							d.pop_back();
						else
							continue;
					}
					else
					{
						d.push_back(t);
					}

					cout << d << "\n\t\t";
					if (d != "")
					{
						cout << "SUUGESTED WORDS\n";
						temp2=t1.search(d);
					}

				}
				else
					continue;

			}
			
			list* l2 = new list;
			if (s != "" && d != ""&&temp1==1&&temp2==1)
			{
				system("cls");
				cout<<temp1<<endl<<temp2;
				cout << "\n\t\tYOU SEARCHED FOR: " << s << " AND(&&) " << d << "\n\t\t";
				//cout << h1.findkey(d);
				/*cout << "n1\n";*/
				n1 = h1.searchword(s, 0);
				/*cout << "n2\n";*/
				n2 = h1.searchword(d, 0);
				l2->and_search(n1, n2);
				cout << "\n";

				if (l2->gethead() == NULL)
					cout << "\nNO FILE FOUND\n";
				else
				{
					l2->removeduplicates();
					l2->printlist(s, d, 0);
					cout << "\nDO YOU WANT TO OPEN THESE FILES TO SEE WHERE THE WORD IS PRESENT\n1. YES\n2. NO\n";
					int ch;
					cin >> ch;
					if (ch == 1)
					{
						system("cls");
						l2->printlist(s, d, 1);
					}
				}

			}
			else
			{
				cout << "\n\t\tNO INPUT\n\t\t";
				goto agai;
			}
			delete l2;
		}
		else if (choice == 4)
		{
			menu(h1, t1);
		}
		else
		{
			"wrong!";
			goto agai;
		}

	}
};
class admin
{
	string username;
	string password;
public:
	bool checkusername()
	{
		string word;
		cout << "ENTER THE USERNAME: ";
		cin >> username;
		ifstream fin;
		fin.open("username.dat", ios::in);
		fin >> word;
		fin.close();
		if (word == username)
		{
			return true;
		}
		else
			return false;
	}
	bool checkpassword()
	{
		string word;
		char pass[20];
		int i = 0;
		cout << "ENTER THE PASSWORD: ";

		char ch;
		while (1)
		{
			ch = _getch();
			if (ch == 13)
			{
				pass[i] = '\0';
				break;
			}
			else if (ch == 8 && i > 0)
			{
				i--;
				cout << "\b \b";
			}
			else
			{
				cout << "*";
				pass[i] = ch;
				i++;
			}
		}
		ifstream fin;
		fin.open("password.dat", ios::in);
		fin >> word;
		fin.close();
		if (pass == word)
			return true;
		else
			return false;
	}
	void adminaddnewfile(hashtable& h1, trie& t1)
	{
		char data[100];
		int nofile;
		fflush(stdin);
		cout << "\n\t\tENTER THE DATA YOU WANT TO STORE IN THE FILE\n\t\t";
		cin.getline(data, 100);
		nofile = h1.addnewfile(data);
		t1.addnewfile(nofile);
		cout << "\n\t\tPRESS ANY KEY";
		_getch();
		//adminmenu();
	}
	int adminmenu()
	{
		int choice;
		cout << "\n\n\t\t1.INSERT NEW FILE\n\t\t2.RETURN TO MAIN MENU\n\t\t";
		cin >> choice;
		return choice;
	}
};
void menu(hashtable& h11, trie& t11)
{
	user u1;
	admin a1;
	int choice;
ag:
	system("cls");
	cout << "\n\n\n\t\t\t1.ADMIN\n\t\t\t2.USER\n\t\t\t3.EXIT\n\t\t\t";
	cin >> choice;
	if (choice == 1)
	{
		system("cls");
		int ch;
		bool flag1, flag2;
	retry:
		flag1 = a1.checkusername();
		flag2 = a1.checkpassword();
		if (flag1 && flag2)
		{
			cout << "\nWELCOME ADMIN\n";
			//Sleep(100);(100);(100);(100);(100);(100);(100);(100);(100);(100);
		aga:
			system("cls");
			ch = a1.adminmenu();
			if (ch == 1)
			{
				a1.adminaddnewfile(h11, t11);
				goto ag;
			}
			else if (ch == 2)
			{
				menu(h11, t11);
			}
			else
			{
				cout << "\nWRONG INPUT\nPRESS ANY KEY TO TRY AGAIN\n";
				_getch();
				goto aga;
			}
		}

		else
		{
			cout << "\n\t\tNOT CORRECT\n\t\tPLEASE TRY AGAIN\n";
			_getch();
			goto retry;
		}

	}
	else if (choice == 2)
	{
	h:
		system("cls");
		u1.search(h11, t11);
		_getch();
		system("cls");
		cout << "\nPRESS 1 TO SEARCH AGAIN\n";
		int ch;
		cin >> ch;
		if (ch == 1)
		{
			system("cls");
			goto h;
		}
		else
			menu(h11, t11);
	}
	else if (choice == 3)
	{
		exit(1);
	}
	else
		goto ag;

}
int main()
{
	system("COLOR 79");
	cout << "\n\n\t\tWELCOME TO HSM SEARCH ENGINE\n\n";

	trie t11;
	t11.writepreviousfiles();
	hashtable h11;

//	cout << h11.sizefiles();
//
//	h11.readallfiles();
	h11.writepreviousfiles();
	//h11.printtable();
	menu(h11, t11);


}
