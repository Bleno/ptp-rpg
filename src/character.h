#ifndef CHARACTER_H_
#define CHARACTER_H_ 


/*
  WARRIOR
 */
#define WARRIOR_HP 700
#define WARRIOR_DAMAGE 100

/*
  ARROW
 */
#define ARROW_HP 600
#define ARROW_DAMAGE 100

/*
  WIZARD
 */
#define WIZARD_HP 500
#define WIZARD_DAMAGE 100



// Charazou
struct character {
	float hp;
	float damage;
};


struct character create_character(int t );

#endif /* CHARACTER_H_ */