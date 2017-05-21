class RenderTargets
{
			class DriverCam
			{
				renderTarget = "rendertarget1";
					class CameraView1
					{
						pointPosition = "driverview";
						pointDirection = "pip_driver_dir";
						renderQuality = 2;
						renderVisionMode = 0;
						fov = 0.75;
					};
			};	
			
			class GunnerCam
			{
				renderTarget = "rendertarget2";
					class CameraView1
					{
						pointPosition = "gunnerview";
						pointDirection = "pip_gunner_dir";
						renderQuality = 2;
						renderVisionMode = 0;
						fov = 0.75;
					};
			};	
			class GunnerCam2
			{
				renderTarget = "rendertarget4";
					class CameraView1
					{
						pointPosition = "gunnerview";
						pointDirection = "pip_gunner_dir";
						renderQuality = 2;
						renderVisionMode = 0;
						fov = 0.75;
					};
			};
			
			class DriverCam2
			{
				renderTarget = "rendertarget3";
				class CameraView1
					{
						pointPosition = "driverview";
						pointDirection = "pip_driver_dir";
						renderQuality = 2;
						renderVisionMode = 0;
						fov = 0.75;
					};
			};	
		};