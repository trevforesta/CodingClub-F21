// Trevor Foresta
// Kattis: Bank 

#include <stdio.h>  
#include <vector>
#include <algorithm> 
using namespace std; 

struct Person{
    int money;
    int time;
    
    Person(int m, int w){
        money = m;
        time = w;
    }
};

bool compareMoney(const Person &a, const Person &b){
        return a.money >= b.money;
}

void queuePerson(vector<int> &v, Person c){
    int i = c.time;
    
    while(i >= 0){
        if(v[i] == 0){
            v[i] = c.money;
            return;
        }  
        i--;
    }
}

int main(){ 
	// N = number of people in the queue
	// T = time in minutes until bank closes
	// ci = amount of crowns that person i has
	// ti = time until person i leaves if not served
    int N, T, ci, ti;
    int sum = 0;
    int i = 0;
	
    scanf("%d %d", &N, &T);
    
    // declair bQueue and money
    vector<int> bQueue(T);
    vector<Person> money;
    
    for(int i = 0; i < N; i++){
        scanf("%d %d", &ci, &ti);
        Person c(ci, ti);
        
		// adds a new element at the end of the vector, after its current last element. The content of c is copied to the new element.
        money.push_back(c); 
    }
    
	// sorts the elements in the range [first,last) into ascending order.
    sort(money.begin(), money.end(), compareMoney);
    
    // queue the person's time with money
    while(i < money.size()){
        queuePerson(bQueue, money[i]);
        i++;
    }
    
    // serve eveyone inside the bQueue.
    for(int i = 0; i < bQueue.size(); i++){
        sum += bQueue[i];
    }
    
    printf("%d", sum); // print maximum amount of money you can take from the queue before the bank closes
    return 0; // end of program
}