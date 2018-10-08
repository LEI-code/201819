class Point{
	Point(int px, int py){this.x = px; this.y = py;}
	public int x, y;
}

class Circle{
	//a circle with radius 0 can still be considered a circle. A degenerate circle.
	//by definition, nothing prohibits a circle from having 0 radius, though things such 
	//as tangents might have to specify in their own definition that the radius mustn't be 0
	//so if we were to extend this class to include such operations, the way to go would prob
	//be to throw an exception once the condition wasn't met in the corresponding function,
	//and not prohibit a 0 radius instance of the class from even being created in the first place
	//sources:
	//http://mathforum.org/library/drmath/view/66132.html
	//https://www.quora.com/Can-a-circle-have-no-area-i-e-can-a-circle-have-a-radius-of-0
	//https://en.wikipedia.org/wiki/Degeneracy_(mathematics)
	Circle(double pr){
		if(pr<0)throw new IllegalArgumentException("Circle radius cannot be < 0!");
		this.r = pr;
	}
	//in this particular instance it might come in handy to not have a location
	//for the circle if our operation doesn't require it, so not checking for a 
	//nullptr might be the way to go. Might also be dangerous in the future,
	//but I believe the programmer should be smart about the way he/she programs
	//and read the documentation (or commentary) of the code they're using, allowing
	//the underlying code to be as versatile as possible, and doing the checks themselves
	//in this instance it saves memory, time, and the garbo collector some trouble
	Circle(Point ppos, double pr){this(pr); this.pos = ppos;}
	Circle(int px, int py, double pr){this(pr); this.pos = new Point(px, py);}

	public Point pos;
	public double r;

	public double area(){
		return Math.PI * this.r * this.r;
	}
}

class T1_C{
	public static void main(String[] args) {
		java.util.Scanner sc = new java.util.Scanner(System.in);
		System.out.println("" + (int)(new Circle(null, sc.nextFloat())).area());
	}
}