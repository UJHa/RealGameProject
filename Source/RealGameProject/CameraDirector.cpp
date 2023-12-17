// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraDirector.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACameraDirector::ACameraDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	NowCameraIndex = 0;
}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const float TimeBetweenCameraChanges = 2.0f;
	const float SmoothBlendTime = 0.75f;

	TimeToNextCameraChange -= DeltaTime;
	if (TimeToNextCameraChange <= 0.0f)
	{
		FChangeCameraData nowCamera = Cameras[NowCameraIndex];
		TimeToNextCameraChange += nowCamera.TimeBetweenCameraChanges;
		NowCameraIndex = (NowCameraIndex + 1) % Cameras.Num();
		APlayerController* controller = UGameplayStatics::GetPlayerController(this, 0);
		if (controller)
		{
			if ((controller->GetViewTarget() != nowCamera.Camera) && (nowCamera.Camera != nullptr))
			{
				if (nowCamera.SmoothBlendTime <= 0.0f)
				{
					controller->SetViewTarget(nowCamera.Camera);
				}
				else
				{
					controller->SetViewTargetWithBlend(nowCamera.Camera, nowCamera.SmoothBlendTime);
				}
			}
		}
	}
}

