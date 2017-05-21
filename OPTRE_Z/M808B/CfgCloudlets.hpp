class CfgCloudlets {
    class MachineGunCartridge2;
    class OPTRE_90mmShellcase: MachineGunCartridge2 {
        moveVelocity[] = { "-directionX * 2", "- directionY", "- directionZ" };
		//        moveVelocity[] = { "-directionX * 6", "- directionY * 6", "- directionZ * 3" };
        particleShape = "M808B\90mm_shellcase.p3d";
        size[] = {1};
        sizeVar = 0;
    };

};

class OPTRE_90mmShellcase {
    class OPTRE_90mmShellcase {
        simulation = "particles";
        type = "OPTRE_90mmShellcase";
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 0.05;
        qualityLevel = 2;
    };
    class OPTRE_90mmShellcase_med: OPTRE_90mmShellcase {
        qualityLevel = 1;
    };

};