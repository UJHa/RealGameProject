// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "RealGameProject.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Log, TEXT("Contructor"));
	TotalDamage = 200;
	DamageTimeInSeconds = 1.0f;
	CharacterName = TEXT("Taid");
	bAttackable = true;

	str = TEXT("TEST");
}

void AMyActor::CallFromCpp_Implementation()
{
	str.Append(TEXT("_Implementation"));
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("BeginPlay"));
	UE_LOG(LogTemp, Error, TEXT("Error Test"));
	UE_LOG(LogTemp, Warning, TEXT("Warning Test"));
	UE_LOG(LogTemp, Display, TEXT("Display Test"));
	UE_LOG(MyLogCategory, Log, TEXT("MyLogCategory Test"));
	
	UE_LOG(MyLogCategory, Log, TEXT("str Name = %s"), *str);

	UE_LOG(MyLogCategory, Log, TEXT("str Name = %s, TotalDamage = %d, DamageTimeInSeconds = %f"), *str, TotalDamage, DamageTimeInSeconds);
	CallFromCpp();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Log, TEXT("Tick"));

}

void AMyActor::TestFunction()
{

}

void AMyActor::CalculateDPS()
{
	DamagePerSecond = TotalDamage / DamageTimeInSeconds;
}

void AMyActor::PostInitProperties()
{
	Super::PostInitProperties();
	CalculateDPS();
}

void AMyActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	CalculateDPS();
	Super::PostEditChangeProperty(PropertyChangedEvent);
}
