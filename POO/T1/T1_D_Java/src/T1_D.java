class Point{
	Point(double px, double py){this.x = px; this.y = py;}
	public double x, y;
	public String toString(){return ""+ x + " " + y;}
	public String toStringInt(){return ""+ (int)x + "@" + (int)y;}
}

class LineSegment{
	LineSegment(Point pa, Point pb){
		if(pa.x == pb.x && pa.y == pb.y)throw new IllegalArgumentException("Two equal points do not make up a line segment!");
		this.a = pa;
		this.b = pb;
	}
	LineSegment(double x1, double y1, double x2, double y2){
		if(x1 == x2 && y1 == y2)throw new IllegalArgumentException("Two equal points do not make up a line segment!");
		this.a = new Point(x1, y1);
		this.b = new Point(x2, y2);
	}

	private Point a, b;

	public double middlePointX(){
		return (a.x + b.x) / 2;
	}
	public double middlePointY(){
		return (a.y + b.y) / 2;
	}
	public Point middlePoint(){
		return new Point(this.middlePointX(), this.middlePointY());
	}
}

class T1_D{
	public static void main(String[] args) {
		java.util.Scanner sc = new java.util.Scanner(System.in);
		try{
			System.out.println("" + 
				(new LineSegment(
					sc.nextDouble(), sc.nextDouble(), sc.nextDouble(), sc.nextDouble())
				).middlePoint().toStringInt()
			);
		}catch (IllegalArgumentException e){
			System.out.println("shoarb");
			System.exit(0);
		}
	}
}