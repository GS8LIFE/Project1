#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void makeSound() const = 0; 
    virtual ~Animal() {} 
};

class Dog : public Animal 
{
public:
    void makeSound() const override 
    {
        cout << "멍" << endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound() const override
    {
        cout << "냥" << endl;
    }
};

class Cow : public Animal 
{
public:
    void makeSound() const override
    {
        cout << "음매" << endl;
    }
};
// 여기서부턴 도전
class Zoo 
{
private:
    Animal* animals[10]; 
    int count; 
public:
    Zoo() : count(0) {}

    void addAnimal(Animal* animal) 
    {
        if (count < 10) {
            animals[count++] = animal;
        }
        else {
            cout << "동물이 가득 참" << endl;
        }
    }

    void performActions() {
        for (int i = 0; i < count; i++) 
        {
            animals[i]->makeSound();
        }
    }

    ~Zoo() {
        for (int i = 0; i < count; i++) 
        {
            delete animals[i];
        }
    }
};

Animal* createRandomAnimal() 
{
    int random = rand() % 3; 
    if (random == 0) 
    {
        return new Dog();
    }
    else if (random == 1) 
    {
        return new Cat();
    }
    else 
    {
        return new Cow();
    }
}


int main()
{
    Animal* animals[3];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Cow();

    for (int i = 0; i < 3; i++)
    {
        animals[i]->makeSound();
    }

    for (int i = 0; i < 3; i++) 
    {
        delete animals[i];
    }


    //도전

    srand(static_cast<unsigned int>(time(0))); // 랜덤 시드 설정

    Zoo zoo;

    for (int i = 0; i < 5; i++) {
        Animal* animal = createRandomAnimal();
        zoo.addAnimal(animal);
    }

    // 동물원에서 모든 동물의 행동 수행
    zoo.performActions();

    return 0;
}