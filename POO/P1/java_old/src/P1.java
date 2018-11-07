class Point{
	Point(double x, double y){
		this.x = x; this.y = y;
	}
	Point(Point p){
		this.x = p.x; this.y = p.y;
	}
	static double Distance(double x1, double y1, double x2, double y2){
		return Math.sqrt((x1 - x2)*(x1 - x2)+(y1 - y2)*(y1 - y2));
	}
	double dist(Point p){
		return Distance(this.x, this.y, p.x, p.y);
	}
	double dist(double x, double y){
		return Distance(this.x, this.y, x, y);
	}

	public double x;
	public double y;
}

class Vector{
	Vector(Point a, Point b){
		this.x = b.x - a.x;
		this.y = b.y - a.y;
	}
	Vector(double x, double y){
		this.x = x; this.y = y;
	}

	boolean equals(Vector v){
		return x == v.x && y == v.y;
	}
	boolean equals_neg(Vector v){
		return (Math.abs(x) == Math.abs(v.x) && y == v.y) || (x == v.x && Math.abs(y) == Math.abs(v.y));
	}

	double mangitude(){
		return Math.sqrt(this.x*this.x + this.y*this.y);
	}
	double dotProduct(Vector v){
		return this.x * v.x + this.y * v.y;
	}
	Vector getNormalized(){
		return new Vector(x/this.mangitude(), y/this.mangitude());
	}

	public double x, y;
}

class BufferedAverage{
	BufferedAverage(){this.sum = 0; this.nrOfElements = 0;}

	void add(double nr){this.nrOfElements++; this.sum+=nr;}
	void rem(double nr){this.nrOfElements--; this.sum-=nr;}

	boolean ready(){return this.nrOfElements != 0;}
	double get() throws java.lang.IllegalStateException{
		if(this.nrOfElements == 0)
			throw new java.lang.IllegalStateException("There must be at least 1 element for an average to be possible!");
		return (double)this.sum/(double)this.nrOfElements;
	}

	private double sum;
	private int nrOfElements;
}

class Triangle{
	public Triangle(Point a, Point b, Point c){
		this.a = a; this.b = b; this.c = c;
		this.ab = a.dist(b);
		this.bc = b.dist(c);
		this.ca = c.dist(a);
	}
	public boolean isValid(){
		return (ab < bc + ca) && (bc < ab + ca) && (ca < ab + bc); 
			//if the points are collinear one of these must fail 
			//because the sum of the distance the 2 "inner" sides 
			//will be ->equal<- to the that of the larger side
			//same thing for if all sides are the same point
	}
	public boolean isEquilateral(){
		return ab == bc && bc == ca;
	}
	public double perimeter(){
		return ab+bc+ca;
	}
	public double area(){
		double p = this.perimeter();
		return Math.sqrt(p*(p-ab)*(p-bc)*(p-ca));
	}

	private double ab, bc, ca;
	private Point a, b, c;
}

class ConvexQuadrilateral{
	public ConvexQuadrilateral(Point a, Point b, Point c, Point d){
		this.a = a; this.b = b;
		this.c = c; this.d = d;
		//ab = new Vector(this.a, this.b);
		//bc = new Vector(this.b, this.c);
		//cd = new Vector(this.c, this.d);
		//da = new Vector(this.d, this.a);
	}
	public boolean isValid(){
		if(a == null || b == null || c == null || d == null)return false;
		Triangle abc = new Triangle(this.a, this.b, this.c);
		Triangle abd = new Triangle(this.a, this.b, this.d);
		Triangle adc = new Triangle(this.a, this.d, this.c);
		Triangle dbc = new Triangle(this.d, this.b, this.c);
		double a1 = abc.area(); double a2 = abd.area();
		double a3 = adc.area(); double a4 = dbc.area();
		return (a1 == a2+a3+a4) || (a2 == a1+a3+a4) || (a3 == a1+a2+a4) || (a4 == a1+a2+a3);
	}
	public void unCross(){
		double areaThis = 
			 (new Triangle(this.d, this.b, this.c)).area()
			+(new Triangle(this.d, this.b, this.a)).area();
		double areaABswitched = 
			 (new Triangle(this.d, this.a, this.c)).area()
			+(new Triangle(this.d, this.a, this.b)).area();
		double areaBCswitched = 
			 (new Triangle(this.d, this.c, this.b)).area()
			+(new Triangle(this.d, this.c, this.a)).area();
		if(areaBCswitched > areaThis){
			Point b_ = this.b;
			this.b   = this.c;
			this.c   = b_;
		}else if(areaABswitched > areaThis){
			Point b_ = this.b;
			this.b   = this.a;
			this.a   = b_;
		}
		
	}
	public boolean isParallelogram(){ 	//assumes is convex quad
		return (new Vector(a, b)).equals_neg((new Vector(c, d))) && (new Vector(b, c)).equals_neg((new Vector(d, a)));
	}
	public boolean isRectangle(){		//assumes is parallelogram
		return ((new Vector(a, b)).dotProduct((new Vector(b, c)))) == 0;
	}
	public boolean isSquare(){			//assumes is rectangle
		return a.dist(b) == b.dist(c);
	}
	public double perimeter(){
		return a.dist(b) + b.dist(c) + c.dist(d) + d.dist(a);
	}

	//private Vector ab, bc, cd, da;
	private Point a, b, c, d;
}

class Mesh{
	public Mesh(int pointAmount){
		this.centerX = new BufferedAverage();
		this.centerY = new BufferedAverage();
		this.points = new Point[pointAmount];
		this.distsToCenter = null;
		this.finalized = false;
		this.currentPoint = 0;
	}
	public void push(Point p){
		if(this.currentPoint == this.points.length)
			throw new java.lang.IllegalStateException("Mesh Was Full");
		this.centerX.add(p.x);
		this.centerY.add(p.y);
		this.points[this.currentPoint++] = p;
	}
	public void pop(){
		if(this.currentPoint == 0)
			throw new java.lang.IllegalStateException("Mesh Was Empty");
		this.centerX.rem(this.points[this.currentPoint].x);
		this.centerY.rem(this.points[this.currentPoint].y);
		this.points[--this.currentPoint] = null;
	}
	//must have all points for this
	public boolean lock(){
		if(this.currentPoint != this.points.length)return false;
		Point center = new Point(this.centerX.get(), this.centerY.get());

		this.distsToCenter = new double[this.points.length];
		for (int i = 0; i < this.points.length; i++)
			this.distsToCenter[i] = center.dist(points[i]);

		this.finalized = true;
		return true;
	}

	public boolean unlock(){
		this.cachedFurthest = null;
		this.distsToCenter = null;
		this.finalized = false;
		return true;
	}

	private Point[] furthest4(){
		if(this.cachedFurthest != null)return this.cachedFurthest;
		this.cachedFurthest = new Point[4];
		double[] furthestFound = new double[4];

		for (int i = 0; i < this.points.length; i++) { 			//for every point
			for (int c = 0; c < 4; c++) {						//look in the array for a value that's <= than current point
				if(this.distsToCenter[i] > furthestFound[c]){	//if found
					for (int r = 3; r > c; r--)					//push everything down from the one we found
						this.cachedFurthest[r] = this.cachedFurthest[r-1];
					this.cachedFurthest[c] = this.points[i];
					furthestFound[c] = this.distsToCenter[i];	//set the one we just freed space for
					break;										//look for the next point
		}	}	}
		//for (int i = 0; i < 4; i++)System.out.println(i + ": " + this.cachedFurthest[i]);
		return this.cachedFurthest;
	}

	public Triangle getTriangle(){
		Point[] furthestPoints = this.furthest4();
		return new Triangle(furthestPoints[0], furthestPoints[1], furthestPoints[2]);
	}
	public ConvexQuadrilateral getQuad(){
		Point[] furthestPoints = this.furthest4();
		return new ConvexQuadrilateral(furthestPoints[0], furthestPoints[1], furthestPoints[2], furthestPoints[3]);		
	}

	private boolean finalized;

	private BufferedAverage centerX;
	private BufferedAverage centerY;

	private int currentPoint;
	private Point[] points;
	private double[] distsToCenter;

	//use to single function
	private Point[] cachedFurthest;
}


class P1{
	public static void main(String[] args) {
		java.util.Scanner sc = new java.util.Scanner(System.in);
		int pa = sc.nextInt();
		Mesh memesh = new Mesh(pa);
		for(int x = 0; x < pa; x++)
			memesh.push(new Point(sc.nextDouble(), sc.nextDouble()));
		memesh.lock();
		ConvexQuadrilateral quadAttempt = memesh.getQuad();
		if(quadAttempt.isValid()){
			if(quadAttempt.isParallelogram()){
				if(quadAttempt.isRectangle()){
					if(quadAttempt.isSquare()){
						System.out.print("Square ");
					}else{
						System.out.print("Rectangle ");
					}
				}else{
					System.out.print("Parallelogram ");
				}
			}else{
				System.out.print("Convex Quadrilateral ");
			}
			System.out.println(quadAttempt.perimeter());
		}else{
			Triangle triAttempt = memesh.getTriangle();
			if(triAttempt.isValid()){
				if(triAttempt.isEquilateral()){
					System.out.print("Equilateral Triangle ");
				}else{
					System.out.print("Triangle ");
				}
				System.out.println(triAttempt.perimeter());
			}else{
				System.out.println("Not a Quadrilateral nor a Triangle");
			}
		}

	}
}