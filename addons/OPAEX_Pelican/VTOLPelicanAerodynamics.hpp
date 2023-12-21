//===============================================================================================
//Aerodynamics
//===============================================================================================
angleOfIndicence = "1*3.1415/180"; //angleOfIndicence = "3*3.1415/180";
landingAoa = "10*3.1415/180";
stallSpeed = 180; //Stall speed and landingAoA are AI suggestions.
stallWarningTreshold = 0.2; //Percent of airspeed to begin warning.

envelope[] = {0, 0.01, 0.2, 4, 6, 7.6, 8.4, 9.2, 9.4, 9.6, 9.7, 9.8, 8, 1};

airBrake = 1;
flaps = 0;
tailHook = 0;
flapsFrictionCoef = 0;

aileronSensitivity = 1;
aileronCoef[] = {1.0, 1.4, 1.9, 2, 2.05, 2.1, 2.15}; //{0, 0.5, 0.9, 1, 1.05, 1.1, 1.12};
aileronControlsSensitivityCoef = 1;
VTOLRollInfluence = 18;

elevatorSensitivity = 1;
elevatorCoef[] = {1.0, 1.4, 1.9, 2, 2.05, 2.1, 2.15}; //{0, 0.4, 0.9, 1, 1.05, 1.1, 1.15};
elevatorControlsSensitivityCoef = 1;
VTOLPitchInfluence = 16;

rudderInfluence = 0.999;
rudderCoef[] = {12.0, 12.4, 12.9, 13, 13.05, 13.1, 13.15};
rudderControlsSensitivityCoef = 1;
VTOLYawInfluence = 20;

draconicForceXCoef = 10;
draconicForceYCoef = 1;
draconicForceZCoef = 1;
draconicTorqueXCoef[] = {0.5, 1, 2, 2.3, 3, 2.6, 2.4, 2.2, 2, 1.9, 1.8}; //{14, 12, 11.2, 10.6, 9.9, 9.6, 9.7, 10.5, 11, 11.5, 12};
draconicTorqueYCoef[] = {0.5, 1, 2, 2.3, 3, 2.6, 2.4, 2.2, 2, 1.9, 1.8};

//Taken from the A-164 wipeout.
/*
Note, these air frictions are a polynomial system!
The variable component is the object's speed in a given component.
You can view this as a system of 3 equations; Think of these frictions as a matrix.

airFrictionCoefs2^2 * x + airFrictionCoefs1 * x + airFrictionCoefs0 = x-friction
The axes are in model space X, Y, Z.
 */
airFrictionCoefs2[] = {0.001, 0.006, 7e-005};
airFrictionCoefs1[] = {0.1, 0.6, 0.0067};
airFrictionCoefs0[] = {0, 0, 0};