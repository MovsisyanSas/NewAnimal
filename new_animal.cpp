#include <iostream>

class animal {
public:
	std::string ability;
	std::string heart;
	std::string eye;
	std::string mouth;
	std::string ears;
    std::string movement;
	int by;

	animal(int birthYear) : ability("can breath,eat,drink,live,move"), heart("heart"), eye(",eye"), mouth(",mouth"), ears(",ears"), movement("by limbs"), by(birthYear){
		/*display();
		move();*/
	}
	animal(animal&& obj) {
		this->ability = obj.ability;
		this->heart = obj.heart;
		this->eye = obj.eye;
		this->mouth = obj.mouth;
		this->ears = obj.ears;
		this->movement = obj.movement;
		this->by = obj.by;

		obj.by = 0;
		obj.ability = '\0';
		obj.heart = '\0';
		obj.eye = '\0';
		obj.mouth = '\0';
		obj.ears = '\0';
		obj.movement = '\0';
		std::cout << "animal class move constructor" << std::endl;
	}
	animal& operator = (animal&& obj) {
		if (this != &obj)
		{
			this->ability = obj.ability;
			this->heart = obj.heart;
			this->eye = obj.eye;
			this->mouth = obj.mouth;
			this->ears = obj.ears;
			this->movement = obj.movement;
			this->by = obj.by;

			obj.by = 0;
			obj.ability = '\0';
			obj.heart = '\0';
			obj.eye = '\0';
			obj.mouth = '\0';
			obj.ears = '\0';
			obj.movement = '\0';
		}
		std::cout << "animal class move operator =" << std::endl;
		return *this;
	}
	virtual ~animal() {
		//std::cout << "animal class destructor" << std::endl;
	}
public:
	virtual void display() {
		std::cout << ability << std::endl;
		std::cout << std::endl;
		std::cout << "parts of body: " << heart << eye << mouth << ears << std::endl;
		std::cout << std::endl;
		std::cout << "Birth year: " << by << std::endl;
	}
	virtual void move() {
		std::cout << movement << std::endl;
	}

};

class mammal : public animal {
public:
	std::string mammalAbility;
	std::string teeth;
	std::string legs;
	std::string hand;
	std::string hair;
	std::string mammalMovement;
	int age;

	mammal(int Age) : animal(2023-Age), mammalAbility(",walk better,more flexible,smarter,wilder"), teeth(",teeth"), legs(",legs"), hand(",hand"), hair(",hair"), mammalMovement("walking/running/jumping"),age(Age) {
		/*display();
		move();*/
	}
	mammal(mammal&& obj) : animal(std::move(obj)) {
		this->mammalAbility = obj.mammalAbility;
		this->teeth = obj.teeth;
		this->legs = obj.legs;
		this->hand = obj.hand;
		this->hair = obj.hair;
		this->mammalMovement = obj.mammalMovement;
		this->age = obj.age;

		obj.age = 0;
		obj.mammalMovement = '\0';
		obj.hair = '\0';
		obj.hand = '\0';
		obj.legs = '\0';
		obj.teeth = '\0';
		obj.mammalAbility = '\0';
		std::cout << "mammal class move constructor" << std::endl;
	}
	mammal& operator = (mammal&& obj) {
		if (this != &obj)
		{
			this->mammalAbility = obj.mammalAbility;
			this->teeth = obj.teeth;
			this->legs = obj.legs;
			this->hand = obj.hand;
			this->hair = obj.hair;
			this->mammalMovement = obj.mammalMovement;
			this->age = obj.age;

			obj.age = 0;
			obj.mammalMovement = '\0';
			obj.hair = '\0';
			obj.hand = '\0';
			obj.legs = '\0';
			obj.teeth = '\0';
			obj.mammalAbility = '\0';
		}
		std::cout << "mammal class move operator =" << std::endl;
		return *this;
	}

	~mammal() override {
		//std::cout << "Mammal class destructor" << std::endl;
	}
public:
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
};

class lion : public mammal {
public:
	std::string lionAbility;
	std::string milk;
	std::string muscles;
	std::string LionMovement;
	int AgeByDays;
	lion(int AgeBD) : mammal(AgeBD / 365), lionAbility(",strongest mammal, brave, orange"), milk(",milk"), muscles(",muscles"), LionMovement("walking/running/jumping"),AgeByDays(AgeBD) {
		/*display();
		move();*/
	}
	lion(lion&& obj) : mammal(std::move(obj)) {
		this->lionAbility = obj.lionAbility;
		this->milk = obj.milk;
		this->muscles = obj.muscles;
		this->LionMovement = obj.LionMovement;
		this->AgeByDays = obj.AgeByDays;

		obj.AgeByDays = 0;
		obj.LionMovement = '\0';
		obj.muscles = '\0';
		obj.milk = '\0';
		obj.lionAbility = '\0';
		std::cout << "lion class move constructor" << std::endl;
	}
	lion& operator = (lion&& obj) {
		if (this != &obj)
		{
			this->lionAbility = obj.lionAbility;
			this->milk = obj.teeth;
			this->muscles = obj.muscles;
			this->LionMovement = obj.LionMovement;
			this->AgeByDays = obj.AgeByDays;

			obj.AgeByDays = 0;
			obj.LionMovement = '\0';
			obj.muscles = '\0';
			obj.milk = '\0';
			obj.lionAbility = '\0';
		}
		std::cout << "lion class move operator =" << std::endl;
		return *this;
	}
	~lion() override final {
		//std::cout << "lion class destructor" << std::endl;
	}
public:
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
};

int main() {
	animal a(std::move(animal(4)));
	animal anim(3);
	anim = std::move(animal(4));

	mammal m(std::move(mammal(10)));
	mammal mamm(3);
	anim = std::move(mammal(10));

	lion l(std::move(lion(100)));
	lion lio(3);
	lio = std::move(lion(100));
}
