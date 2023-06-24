#include <iostream>

class animal {
public:
	const std::string ability;
	const std::string heart;
	const std::string eye;
	const std::string mouth;
	const std::string ears;
	const std::string movement;
	const int by;

	animal(int birthYear) : ability("can breath,eat,drink,live,move"), heart("heart"), eye(",eye"), mouth(",mouth"), ears(",ears"), movement("by limbs"), by(birthYear){
		display();
		move();
	}

	virtual void display() {
		std::cout << ability << std::endl;
		std::cout << std::endl;
		std::cout << "parts of body: " << heart << eye << mouth << ears << std::endl;
		std::cout << std::endl;
		std::cout << "Birth year: "<< by << std::endl;
	}
	virtual void move() {
		std::cout << movement << std::endl;
	}

	virtual ~animal() {
		std::cout << "animal class destructor" << std::endl;
	}
};

class mammal : public animal {
public:
	const std::string mammalAbility;
	const std::string teeth;
	const std::string legs;
	const std::string hand;
	const std::string hair;
	const std::string mammalMovement;
	const int age;

	mammal(int Age) : animal(2023-Age), mammalAbility(",walk better,more flexible,smarter,wilder"), teeth(",teeth"), legs(",legs"), hand(",hand"), hair(",hair"), mammalMovement("walking/running/jumping"),age(Age) {
		display();
		move();
	}

	void display() override {
		std::cout << ability << mammalAbility << std::endl;
		std::cout << std::endl;
		std::cout << "parts of body: " << teeth << legs << hand << hair << std::endl;
		std::cout << std::endl;
		std::cout << "Age: " << age << std::endl;
	}
	void move() override {
		std::cout << mammalMovement << std::endl;
	}

	~mammal() override {
		std::cout << "Mammal class destructor" << std::endl;
	}
};

class lion : public mammal {
public:
	std::string lionAbility;
	std::string milk;
	std::string muscles;
	std::string LionMovement;
	int AgeByDays;
	lion(int AgeBD) : mammal(AgeBD / 365), lionAbility(",strongest mammal, brave, orange"), milk(",milk"), muscles(",muscles"), LionMovement("walking/running/jumping"),AgeByDays(AgeBD) {
		display();
		move();
	}
	void display() override final {
		std::cout << ability << mammalAbility << lionAbility << std::endl;
		std::cout << std::endl;
		std::cout << "parts of body: " << milk << muscles << std::endl;
		std::cout << std::endl;
		std::cout << "Age by Days: " << AgeByDays << std::endl;
	}
	void move() override final {
		if (LionMovement != mammalMovement)
		{
			std::cout << LionMovement << std::endl;
		}
	}
	~lion() override final {
		std::cout << "lion class destructor" << std::endl;
	}
};

int main(){
	lion Lion(36915);
}