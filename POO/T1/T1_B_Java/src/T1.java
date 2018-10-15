//------------//------------//------------//------------//----------MATRIX----------//------------//------------//------------//------------//
class p2 implements Comparable<p2>{
	public int x, y;

	public void set(int X, int Y){
		x = X; y = Y;
	}
	public p2 readPt(java.util.Scanner sc){
		this.set(sc.nextInt(), sc.nextInt());
		return this;
	}
	public double dist(p2 otha){
		return Math.sqrt(Math.pow((this.x - otha.x), 2) + Math.pow((this.y - otha.y), 2));
	}

	public int compareTo(p2 otha) {
		if(otha.x == this.x)return this.y - otha.y;
		else return this.x - otha.x;
	}

	public p2(){}
	public p2(int X, int Y){this.set(X, Y);}
	public p2(java.util.Scanner sc){this.readPt(sc);}
}
class tr{
	p2[] pts = new p2[3];

	public tr readPts(java.util.Scanner sc){
		for(int i = 0; i < 3; i++)pts[i].readPt(sc);
		return this;
	}
	public double[] GetDistances(){
		double[] dists = new double[3];
		dists[0] = pts[0].dist(pts[1]);	//AB
		dists[1] = pts[1].dist(pts[2]);	//BC
		dists[2] = pts[2].dist(pts[0]);	//CA
		return dists;
	}
	public boolean isValid(double[] distances){
		if(distances == null)distances = this.GetDistances(); 				//for single use
		double ab = distances[0], bc = distances[1], ca = distances[2];		//aliasing. Should be optimized.
		return (ab < bc + ca) && (bc < ab + ca) && (ca < ab + bc); 
			//if the points are collinear one of these must fail 
			//because the sum of the distance the 2 "inner" sides 
			//will be ->equal<- to the that of the larger side
			//same thing for if all sides are the same point
	}

	tr(){for(int i = 0; i < 3; i++)pts[i] = new p2();}
	tr(java.util.Scanner sc){this(); readPts(sc);}
}

class TriangleFinder{
	int s = 1, f = 0; //s = second point compare, f = first point compare
	//these are here so that we can progressively look for different "a->b"s
	//so every time we call FindAB, it will keep going with these values
	//10/10 would have done this by just passing them by reference to the function
	//but java is a cancerous language that makes no sense at all
	//I mean jesus, "java is pass by value" -> every time you pass an object it passes
	//a reference. lmao. "hey it's ok, it's just passing the reference by value".
	//it just seems like whoever programmed this language, just quit halfway through
	//and they were like "eh, I don't wanna create copies of the objects cuz that's too
	//hard cuz my code is a mess, so I'll just pass the pointer and tell people
	//it's a reference passed by value. I mean if apple can get away with selling garbage
	//at the price of gold, maybe this'll also work".
	//there's also this class. Main has to be static, and has to be inside a class, so nevermind
	//member variables

	public boolean FindAB(tr HiddenTriangle, p2[] planePoints, double distance){
		//System.out.println("(" + this.f + ", " + this.s + ")");
		for (; this.f < planePoints.length; this.f++){
			for (; this.s < planePoints.length; this.s++){
				if(planePoints[this.f].dist(planePoints[this.s]) == distance){
					HiddenTriangle.pts[0] = planePoints[this.f];
					HiddenTriangle.pts[1] = planePoints[this.s];
					return true;
				}
			}
			this.s = this.f + 2;
		}
		return false;
	}
	public boolean FindBCCA(tr HiddenTriangle, p2[] planePoints, double distanceBC, double distanceCA){
		for (int i = 0; i < planePoints.length; ++i){				//find a -> c
			if(	distanceCA == HiddenTriangle.pts[0].dist(planePoints[i])
				&&											//find b -> c
				distanceBC == HiddenTriangle.pts[1].dist(planePoints[i])
			  ){
				HiddenTriangle.pts[2] = planePoints[i];
				return true;
		}	}
		return false;
	}

	TriangleFinder() {
		java.util.Scanner sc = new java.util.Scanner(System.in);
		boolean CurrSuccess = false;

		tr GoldenTriangle = new tr(sc);
		double[] dists = GoldenTriangle.GetDistances();
		if(!GoldenTriangle.isValid(dists)){System.out.println("Invalid Golden Triangle"); System.exit(0);}

		tr HiddenTriangle = new tr();

		int pointAmount   = 0;
		p2[] planePoints  = new p2[pointAmount = sc.nextInt()];
		for (int i = 0; i < pointAmount; i++)planePoints[i] = new p2(sc);

		CurrSuccess = false;
		
		//since there might be multiple pairs of points where the distance between them is a->b, 
		//we look through them until we find the one that belongs to the triangle
		while(this.FindAB(HiddenTriangle, planePoints, dists[0])){
			if(!this.FindBCCA(HiddenTriangle, planePoints, dists[1], dists[2])){
				//if we couldn't find bc and ca, then our A and B might be switched around, go again
				p2 switcht = HiddenTriangle.pts[0];
				HiddenTriangle.pts[0] = HiddenTriangle.pts[1];
				HiddenTriangle.pts[1] = switcht;
				if(!this.FindBCCA(HiddenTriangle, planePoints, dists[1], dists[2])){
					//if we've switched them and still couldn't find it, then the pair of points
					//with the same distance as a->b doesn't belong to the triangle
					//so we continue the search
					this.s++;
					//System.out.println("continuing search");
					continue;
				}else {CurrSuccess = true; break;}		//success
			}else {CurrSuccess = true; break;}			//success
		}

		if(!CurrSuccess){System.out.println("Couldn't find the triangle"); System.exit(0);}

		java.util.Arrays.sort(HiddenTriangle.pts);

		System.out.println(
			HiddenTriangle.pts[0].x + " " + HiddenTriangle.pts[0].y + "\n" +
			HiddenTriangle.pts[1].x + " " + HiddenTriangle.pts[1].y + "\n" +
			HiddenTriangle.pts[2].x + " " + HiddenTriangle.pts[2].y
		);
	}
}


public class T1{
	public static void main(String[] args) {
		TriangleFinder ey = new TriangleFinder();
	}
}