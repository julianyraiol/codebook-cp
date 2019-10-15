#include <iostream>
#include <vector>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
	
};

class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
        string firstName;
		string lastName;
		int id;

        /*	
        *   Class Constructor
        *   
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */

        Student(string firstName, string lastName, int id, vector<int> scores):Person(firstName, lastName, id){
            this->testScores = scores;
        }

        int median_score(){
            int sum = 0;
            int size = this->testScores.size();

            for(int i = 0; i < size; i++)
                sum+=this->testScores[i];
            
            return sum/size;
        }

        /*	
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */

        char calculate(){
            int median = this->median_score();

            if(median >= 90 && median <= 100)
                return 'O';
            else if(median >= 80 && median < 90)
                return 'E';
            else if(median >= 70 && median < 80)
                return 'A';
            else if(median >= 55 && median < 70)
                return 'P';
            else if(median >= 40 && median < 55)
                return 'D';
            return 'T';            
        }
};

int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}