# include <iostream>
#include<ctime>
#include<cstdlib>
#include<cctype>
#include <string.h>
using namespace std;
struct monster
{
 int strength;
 int dexterity;
 int hp;
 char name[32];
};
struct player
{
 char name[32];
	int strength;
	int dexterity;
	int hp;
	int exp;
 int weapon;
 int armour;
 int shield;
};
struct equipment
{
 char type[16];
 char name[32];
 int bonus;
};
struct rooms
{
	char description[500];
 char name[32];
 int north;
 int south;
 int east;
 int west;
};
void initializeMonsters();
void initializeEquipment();
void initializeRooms();
void initializeBattle();
void initializePlayer();
void giveItem();
int randomNumber(int);
rooms roomsArray[11];
equipment equipmentArray[9];
player character;
monster monsterArray[6];
int main()
{
 initializeMonsters();
 initializeEquipment();
	initializePlayer();
	initializeRooms();
	char move;
	int currentroom = 0;
 cout << "You emerge in the " <<roomsArray[currentroom].name;
 cout << roomsArray[currentroom].description;
	while (character.hp > 0)
 {
	if (roomsArray[currentroom].north != -1)
	{
	   cout << "You may move north \n";
	}
	if (roomsArray[currentroom].south != -1)
	{
	   cout << "You may move south \n";
	}
	if (roomsArray[currentroom].east != -1)
	{
	   cout << "You may move east \n";
	}
	if (roomsArray[currentroom].west != -1)
	{
	   cout << "You may move west \n";
	}
	cout << "please enter your move: " << endl;
	cin >> move;
	move = toupper(move);
	if (move == 'E')
 currentroom = roomsArray[currentroom].east;
	if (move == 'W')
	   currentroom = roomsArray[currentroom].west;
	if (move == 'N')
	   currentroom = roomsArray[currentroom].north;
	if (move == 'S')
	   currentroom = roomsArray[currentroom].south;
   if (move == 'C')
	   cout << "You have " << character.hp << " HP." << endl;
	   cout << "You have " << character.strength << " strength." << endl;
	   cout << "You have " << character.dexterity << " dexterity." << endl;
	if (move != 'E' && move != 'W' && move != 'S' && move!= 'N')
	cout << "Please insert either 'N', 'E', 'S' or 'W'! " << endl;
	cout << "You emerge in the " << roomsArray[currentroom].name << endl;
	cout << roomsArray[currentroom].description << endl;
	initializeBattle();
	giveItem();
	}
	cout << "You have failed to beat Hannibal and his minions. You have also "
		 << "failed to avenge your Grandfather. What where you thinking going "
		 << "into the castle so weak (*hint make stats higher)!" << endl;
	return 0;
}
void initializeMonsters()
	{
 monsterArray[0].strength = 40;
 monsterArray[0].dexterity = 10;
 monsterArray[0].hp = 30;
 strcpy(monsterArray[0].name, "Orc");
 monsterArray[1].strength = 10;
 monsterArray[1].dexterity = 40;
 monsterArray[1].hp = 30;
 strcpy(monsterArray[0].name, "Elven Archer");
 monsterArray[2].strength = 20;
 monsterArray[2].dexterity = 30;
 monsterArray[2].hp = 30;
 strcpy(monsterArray[0].name, "Undead Corpse");
 monsterArray[3].strength = 30;
 monsterArray[3].dexterity = 30;
 monsterArray[3].hp = 20;
 strcpy(monsterArray[0].name, "Marine");

 monsterArray[4].strength = 30;
 monsterArray[4].dexterity = 30;
 monsterArray[4].hp = 30;
 strcpy(monsterArray[0].name, "Elite Marksman");
 monsterArray[5].strength = 70;
 monsterArray[5].dexterity = 50;
 monsterArray[5].hp = 10;
 strcpy(monsterArray[5].name, "Hannibal");
}
void initializePlayer()
{
 char username[32];

	char move;
	int currentroom = 0;
 cout << "What is your name??? \n" << endl;
 cin >> username;
	cout << "------------------------------------------ \n" << endl;
 strcpy(character.name, username);
 character.hp = 100;
 character.armour=0;
 character.shield=0;
 character.weapon=0;
 cout << endl << username << " Please insert your strength. This will determine the ammount of damage you will inflict. 30-40 is a good ammount. However you may make this number ludacrisly high! \n" <<endl;
	cin >> character.strength;
	cout << "------------------------------------------ \n" << endl;
	cout << endl << username << " Please insert your dexterity. This will determine the ammount of damage that you will have inflicted upon you. The more dexterity, the less total damage. 30 - 40 is a good ammount. Once again you can make this ludacrisly high! \n" << endl;
	cin >> character.dexterity;
	cout << "------------------------------------------ \n" << endl;
	cout << "==========================================" << endl;
 cout << "Brave " << username << " you have just returned from a recent holiday,"
   << "only to find that your village has been pillaged and destroyed."
   << "Upon returning to your hut you see your father, mother and sister"
   << " laying lifeless in pools of their own blood. Without hesitation"
   << " you start sprinting towards Sir Lucifer Hannible's castle."
   << "The castle rests upon a hill that overlooks your town. "
   << "You know that by the end of today you will kill "
   << " hannible and his minions and burn his csatle to cinders."
   << " It is your duty to yourslef and the many villages that surrround yours to"
   << " assasinate this threat. I wish you luck " << username << ". Who am I you ask?"
	<< "I am your dead grandfather that died to the merciless hand of Hannible. "
		 << "Now go grandson."
		 << "At any time (except during battle) you may press 'c' to display your stats!"
		 << "Simply use 'e','w','n' or 's' to navigate, where and as appropriate." << endl;
 cout << "========================================== \n" << endl;
}
void initializeEquipment()
{
 strcpy(equipmentArray[0].type, "Gun");
 strcpy(equipmentArray[0].name, "Berreta");
 equipmentArray[0].bonus = 10;
 strcpy(equipmentArray[1].type, "Gun");
 strcpy(equipmentArray[1].name, "M4 Carbine Rifle");
 equipmentArray[1].bonus = 30;
 strcpy(equipmentArray[2].type, "Gun");
 strcpy(equipmentArray[2].name, "Flamethrower");
 equipmentArray[2].bonus = 50;
 strcpy(equipmentArray[3].type, "Shield");
 strcpy(equipmentArray[3].name, "Homemade wooden sheild");
 equipmentArray[3].bonus = 10;
 strcpy(equipmentArray[4].type, "Shield");
 strcpy(equipmentArray[4].name, "Roman sheild");
 equipmentArray[4].bonus = 30;
 strcpy(equipmentArray[5].type, "Shield");
 strcpy(equipmentArray[5].name, "Heavenly Protection");
 equipmentArray[5].bonus = 50;
 strcpy(equipmentArray[6].type, "Armour");
 strcpy(equipmentArray[6].name, "Flak Jacket");
 equipmentArray[6].bonus = 10;
 strcpy(equipmentArray[7].type, "Armour");
 strcpy(equipmentArray[7].name, "Kevlar SWAT vest");
 equipmentArray[7].bonus = 10;
 strcpy(equipmentArray[8].type, "Armour");
 strcpy(equipmentArray[8].name, "Possesed Armour");
 equipmentArray[8].bonus = 10;
}
void initializeRooms()
{
	strcpy(roomsArray[0].description, "This room is extravagant. There are gold chandaliers on the roof, and a table with gold goblets and plates. There are no windows, and a fireplace to the north illuminates the room. There is a door at the eastern side of the room\n");
 strcpy(roomsArray[0].name, "Foyer Room\n");
	roomsArray[0].north = -1;
	roomsArray[0].south = -1;
	roomsArray[0].east = 1;
	roomsArray[0].west = -1;
	strcpy(roomsArray[1].description, "You emerge into a dark hallway with a single torch in the middle. There are no distinguishing features about this room, and there is a door in the eastern side of the room.\n");
 strcpy(roomsArray[1].name, "Dark Hallway\n");
	roomsArray[1].north = -1;
	roomsArray[1].south = -1;
	roomsArray[1].east = 2;
	roomsArray[1].west = 0;
	strcpy(roomsArray[2].description, "There is a massive fountain in the middle of the room. Its water glows some sort of a heavenly radiance. Upon drinking it you feel revitalised and like a new man. Your HP is restored to its maximum level. There are doors on the northern, eastern and southern sides of the room. \n");
	strcpy(roomsArray[2].name, "Foutain Room\n");
	roomsArray[2].north = 3;
	roomsArray[2].south = 4;
	roomsArray[2].east = 6;
	roomsArray[2].west = 1;
	strcpy(roomsArray[3].description, "Upon stumbling onto this room, you are drenched to your knees in water. As well as being wet, it is also dark and has no distincitive features or items. There are door in on the eastern and southern sides of the room.\n");
	strcpy(roomsArray[3].name, "Swamp\n");
	roomsArray[3].north = -1;
	roomsArray[3].south = 2;
	roomsArray[3].east = 5;
	roomsArray[3].west = -1;
	strcpy(roomsArray[4].description, "A bright lantern illuminates this beatiful room. There are exotic flowers on either sides of it and a treasure chest full of dublons in the top right hand corner. There are doors on the eastern, southern and western sides of the room.\n");
 strcpy(roomsArray[4].name, "Treasure Room\n");
	roomsArray[4].north = 2;
	roomsArray[4].south = -1;
	roomsArray[4].east = 7;
	roomsArray[4].west = -1;
 strcpy(roomsArray[5].description, "Another lusicious and overdone room. Crystals that are on the ground reflect the portraits on the walls. There are doors on the southern and western sides of this room. \n");
 strcpy(roomsArray[5].name, "Counting Room\n");
	roomsArray[5].north = -1;
	roomsArray[5].south = 6;
	roomsArray[5].east = 8;
	roomsArray[5].west = 3;
 strcpy(roomsArray[6].description, "The total opposite of the beatiful fountain room. It reeks of a peculiar smell and is bare with nothing interesting in it. There are doors on every corner of this room. \n");
 strcpy(roomsArray[6].name, "Barn \n");
	roomsArray[6].north = 5;
	roomsArray[6].south = 7;
	roomsArray[6].east = 2;
	roomsArray[6].west = 9;
 strcpy(roomsArray[7].description, "This majestic room has treasure scattered everywhere. In the middle is a large four post king sized bed. There are doors on every corner of this room.\n");
	strcpy(roomsArray[7].name, "Master Bedroom \n");
	roomsArray[7].north = 6;
	roomsArray[7].south = -1;
	roomsArray[7].east = -1;
	roomsArray[7].west = 4;
	strcpy(roomsArray[8].description, "This room is the workers quarters. There are many small uncomfortable beds in running on each wall. There are windows on the northern and eastern walls and doors on the southern and western walls. \n");
	strcpy(roomsArray[8].name, "Minions Quarters \n");
	roomsArray[8].north = -1;
	roomsArray[8].south = 9;
	roomsArray[8].east = -1;
	roomsArray[8].west = 5;
	strcpy(roomsArray[9].description, "What on earth is this. Could it be a mirage? You see luchsious palm tree circling a lagoon with many fish and aquatic lifeforms. There are doors the norhtern, eastern and western sides of the room. \n");
	strcpy(roomsArray[9].name, "Tropical Lagoon \n");
	roomsArray[9].north = 8;
	roomsArray[9].south = -1;
	roomsArray[9].east = 10;
	roomsArray[9].west = 6;
	strcpy(roomsArray[10].description, "The time is now. You see Hannible in his throne. Cigar in one hand, the finest wine in the other. With loud profanity you charge to avenge your grandfather! \n");
	strcpy(roomsArray[10].name, "Hannibles Smoking and Sitting Room \n");
}
void initializeBattle()
{
	int attackstrength = 0;
	int defencestrength = 0;
 int monsterattack = 0;
	int monsterdefence = 0;
	int randommonster = 0;
	srand(static_cast<unsigned>(time(0)));
	randommonster = (rand()%6 + 1);
	cout << "A " << monsterArray[randommonster].name << "Appears. \n" << endl;
	cout << monsterArray[randommonster].name << "has" << monsterArray[randommonster].strength << "strength" << endl
		 << monsterArray[randommonster].name << "has" << monsterArray[randommonster].dexterity << "dexterity" << endl
		 << monsterArray[randommonster].name << "has" << monsterArray[randommonster].hp << "HP \n" << endl;
	do
	{
	  attackstrength = (character.strength + character.weapon) * (rand()%10 + 1);
	  cout << character.name << " deals " << attackstrength << " damage" << endl;
	  monsterdefence = (monsterArray[randommonster].dexterity * (rand()%5+1));
	  cout << monsterArray[randommonster].name << " defends " << monsterdefence << " Hit Points" << endl;
	  if (attackstrength > monsterdefence)
		 {
			 monsterArray[randommonster].hp = monsterArray[randommonster].hp - (attackstrength - monsterdefence);
			 cout << "The monster now has " << monsterArray[randommonster].hp << "Hit points!" << endl;
		 }
	  else
		 {
			 monsterArray[randommonster].hp = monsterArray[randommonster].hp;
			 cout << "You have failed to harm the monster!\n" << endl;
		 }
	  monsterattack = (monsterArray[randommonster].strength * (rand()%5+1));
	  cout << monsterArray[randommonster].name << " does " << monsterattack << "damage!" << endl;
   defencestrength = (character.dexterity + character.shield) * (rand()%5 + 1);
	  cout << character.name << " defends " << defencestrength << "Hit Points!" << endl;
	  if (monsterattack > defencestrength)
		 {
			 character.hp = character.hp - (monsterattack - defencestrength);
			 cout << "You have been hit! You now have " << character.hp << "Hit Points! \n" << endl;
		 }
	  else
		 {
			 character.hp = character.hp;
			 cout << "You have defended the monsters attack! \n ...And now have " << character.hp << "Hitpoints! \n" << endl;
		 }
	}while (monsterArray[randommonster].hp > 0);
}
void giveItem()
{
	 int randomgenerator = 0;
	 srand(static_cast<unsigned>(time(0)));
	 randomgenerator = (rand()%9 + 1);
	 char playerchoice;
	 if (randomgenerator == 0 || randomgenerator == 1 || randomgenerator == 2)
	 {
		cout << "Do you want to pick up the " << equipmentArray[randomgenerator].name << " ?" << endl;
		cout << "This will add " << equipmentArray[randomgenerator].bonus << "to your strength." << endl;
		cout << "(Y)es or (N)o." << endl;
		cin >> playerchoice;
		playerchoice = toupper(playerchoice);
	   if (playerchoice == 'Y')
		   character.weapon = equipmentArray[randomgenerator].bonus;
	   else
		   character.weapon = character.weapon;
	   }
	 else if (randomgenerator == 3 || randomgenerator == 4 || randomgenerator == 5)
	 {
		cout << "Do you want to pick up the " << equipmentArray[randomgenerator].name << " ?" << endl;
		cout << "This will add " << equipmentArray[randomgenerator].bonus << "to your dexterity." << endl;
		cout << "(Y)es or (N)o." << endl;
		cin >> playerchoice;
		playerchoice = toupper(playerchoice);
		if (playerchoice == 'Y')
		   character.shield = equipmentArray[randomgenerator].bonus;
		else
			character.shield = character.shield;
		}
	 else if (randomgenerator == 6 || randomgenerator == 7 || randomgenerator == 8)
	 {
		cout << "Do you want to pick up the " << equipmentArray[randomgenerator].name << " ?" << endl;
		cout << "This will add " << equipmentArray[randomgenerator].bonus << "to your dexterity." << endl;
		cout << "(Y)es or (N)o." << endl;
		cin >> playerchoice;
		playerchoice = toupper(playerchoice);
		if (playerchoice == 'Y')
		   character.armour = equipmentArray[randomgenerator].bonus;
		else
			character.armour = character.shield;
		}
}
