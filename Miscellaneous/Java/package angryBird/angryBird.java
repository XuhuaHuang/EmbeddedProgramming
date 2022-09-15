package angryBird;

public class angryBird {

	private static final double PI = 3.14159265359;
	private static final double G = 9.807;

	// user input attributes:
	private double initVel;
	private double launchAngle;
	private double initHeight;

	// initial data breakdown:
	private double horizVel;
	private double vertiVel;

	// result attributes:
	private double travelTime;
	private double distance;
	private double maxHeight;

	// default constructor:
	public angryBird() {
		setInitVel(0.00);
		setLaunchAngle(0.00);
		setInitHeight(0.00);

		// calculate various parameters
		// function definitions provided later on
		factorVelocity();
		calcParameters();
	}

	// overloaded constructor:
	public angryBird(double userVel, double userAngle, double userHeight) {
		setInitVel(userVel);
		setLaunchAngle(userAngle);
		setInitHeight(userHeight);

		// calculate various parameters
		// function definitions provided later on
		factorVelocity();
		calcParameters();
	}

	// setter and getter for "initVel" - initial velocity
	public void setInitVel(double initVel) {
		if (initVel >= 0.00)
			this.initVel = initVel;
		else
			this.initVel = 0.00;
	}

	public double getInitVel() {
		return initVel;
	}

	// setter and getter for "launchAngle" - launch angle
	public void setLaunchAngle(double launchAngle) {
		if (launchAngle >= 0.00 && launchAngle <= 180)
			this.launchAngle = launchAngle;
		else
			this.launchAngle = 0.00;
	}

	public double getLaunchAngle() {
		return launchAngle;
	}

	// setter and getter for "initHeight" - the height at which the bird is launched
	public void setInitHeight(double initHeight) {
		this.initHeight = initHeight;
	}

	public double getInitHeight() {
		return initHeight;
	}

	// setter and getter for "horizVel" - horizontal velocity
	public void setHorizVel(double horizVel) {
		this.horizVel = horizVel;
	}

	public double getHorizVel() {
		return horizVel;
	}

	// setter and getter for "vertiVel" - vertical velocity
	public void setVertiVel(double vertiVel) {
		this.vertiVel = vertiVel;
	}

	public double getVertiVel() {
		return vertiVel;
	}

	// setter and getter for "travelTime" - time the bird travels in the air
	public void setTravelTime(double travelTime) {
		this.travelTime = travelTime;
	}

	public double getTravelTime() {
		return travelTime;
	}

	// setter and getter for "distance" - horizontal displacement
	public void setDistance(double distance) {
		this.distance = distance;
	}

	public double getDistance() {
		return distance;
	}

	// setter and getter for "maxHeight" - maximum height the bird has reached
	public void setMaxHeight(double maxHeight) {
		this.maxHeight = maxHeight;
	}

	public double getMaxHeight() {
		return maxHeight;
	}

	// other functions:
	// factorization of initial velocity
	public void factorVelocity() {
		// factor and set horizontal velocity
		setHorizVel(getInitVel() * Math.cos(getLaunchAngle() * (PI / 180)));

		// factor and set vertical velocity
		setVertiVel(getInitVel() * Math.sin(getLaunchAngle() * (PI / 180)));
		return;
	}

	// calculate other parameters of projectile
	public void calcParameters() {
		// calculate and set travel time
		setTravelTime((1 / G) * (getVertiVel() + Math.sqrt(Math.pow(getVertiVel(), 2) + 2 * G * getInitHeight())));

		// calculate and set horizontal displacement
		setDistance(getHorizVel() * getTravelTime());

		// calculate and set maximum height
		setMaxHeight(getInitHeight() + Math.pow(getVertiVel(), 2) / (2 * G));
		return;
	}

	// print information
	public void printInfo() {
		System.out.println("\nPrinting information of projectile motion");
		System.out.println("Trajectory information provided is listed as the following: ");

		// initial velocity, launch angle and initial height
		System.out.println("\nThe initial velocity is: " + getInitVel() + " m/s");
		System.out.println("The launch angle of the projectile is: " + getLaunchAngle() + " degrees");
		System.out.println("The initial height of the projectile is: " + getInitHeight() + " meters");

		// horizontal and vertical velocity
		System.out.println("\nAs a result,\n\tthe horizontal velocity is: " + getHorizVel() + " m/s");
		System.out.println("\tthe vertical velocity is: " + getVertiVel() + " m/s");

		// travel time, horizontal displacement and maximum height
		System.out.println("\nThe travel time is: " + getTravelTime() + " s");
		System.out.println("The maximum horizontal displacement is: " + getDistance() + " meters");
		System.out.println("The maximum height the bird has reached is: " + getMaxHeight() + " meters");
	}

} // end angryBird class
