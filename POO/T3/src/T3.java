//DEBUG:
//since this cancer language has no defines 
//or anything useful like that, we're just 
//gonna edit the code with comments for the 
//debugging part, with regexes

//--------------------------------------------regexes for sublime (manual)
//ON_REGEX(SUBLIME):^(\s*)/\*DEBUG_(.*)\*/
//ON_SUBST(SUBLIME):$1/*DEBUG_*/ $2
//OFF_REGEX(SUBLIME):^(\s*)/\*DEBUG_\*/(.*)
//OFF_SUBST(SUBLIME):$1/*DEBUG_ $2*/

//--------------------------------------------regexes for sed (for my comment/uncomment script) 
//ON_REGEX(SED):^(\s*)\/\*DEBUG_(.*)\*\/
//ON_SUBST(SED):\1\/*DEBUG_*\/\2
//OFF_REGEX(SED):^(\s*)\/\*DEBUG_\*\/(.*)
//OFF_SUBST(SED):\1\/*DEBUG_\2*\/

class PirateSolver{

	Boolean[] pirates; //Is Friend
	int friends, enemies;

	PirateSolver(int nr){
		java.util.List<Boolean> piratesTemp = new java.util.ArrayList<Boolean>();

		int digitAmount = (int)(java.lang.Math.log10(nr) + 1);

		/*DEBUG_ System.out.println(digitAmount + " digits");*/

		for (int d = digitAmount-1, i = 0; d >= 0; d--, i++) {

			int currentDigit = ((int)(nr / (Math.pow(10, d)))) % 10; 

			/*DEBUG_ System.out.println((d+1) + "th digit: " + currentDigit);*/

			//add to which one we want
			if((i % 2) == 0)this.enemies += currentDigit;
			else 			this.friends += currentDigit;

			//add to the list
			for (int ai = 0; ai < currentDigit; ai++) piratesTemp.add((i % 2) != 0);
		}
		this.pirates = new Boolean[piratesTemp.size()];
		this.pirates = piratesTemp.toArray(this.pirates);

	}
	public int SolvePirates(){
		int tFriends = 0;					//temporary amount of friends
		int tEnemies = 0;					//temporary amount of enemies
		int currentN = 0; 					//the n
		int totalppl = 0;					//the amount of people left
		int currIndx = 0;					//incremented by n
		java.util.List<Boolean> tPirates;	//temporary list used for calculations

		while(!(tEnemies == 0 && tFriends == friends)){ //while we didn't find a worthy number

			currentN++;									//increase n
			tFriends = this.friends;					//reset temporary friends
			tEnemies = this.enemies;					//reset temporary enemies
			currIndx = currentN;						//reset index
			totalppl = this.pirates.length;				//reset total amount of pirates
			tPirates = new java.util.ArrayList<Boolean>(//reset the array to a new copy
				java.util.Arrays.asList(this.pirates)
			);

			/*DEBUG_ System.out.println("----------------------------------" + currentN + "--------------------------------");*/
			while(friends == tFriends && tEnemies != 0){
				/*DEBUG_ Boolean[] temp = new Boolean[tPirates.size()]; this.PrintArr(tPirates.toArray(temp)); String padding = ""; for (int i = 0; i < (currIndx); i++)padding += "  "; System.out.printf("%s^\n", padding);*/

				if(tPirates.get(currIndx))tFriends--;
				else 					  tEnemies--;

				tPirates.remove(currIndx);
				currIndx = (currIndx + currentN) % tPirates.size();
			}
		}

		return currentN;
	}
	public void PrintArr(Boolean[] prates){
		if(prates == null)prates = this.pirates;

		for (int i = 0; i < prates.length; i++) {
			System.out.print(prates[i] ? "F " : "E ");
		}
		System.out.print("\n");
	}
}

class T3{
	public static void main(String[] args) {
		java.util.Scanner sc = new java.util.Scanner(System.in);
		int result = (new PirateSolver(sc.nextInt())).SolvePirates();
		/*DEBUG_ result++; System.out.println("Every " + result + (((result/10)%10 != 1)?(result%10 == 1)?"st":(result%10 == 2)?"nd":(result%10 == 3)?"rd":"th":"th") + " man"); result--;*/
		System.out.println(result+1);
	}
}