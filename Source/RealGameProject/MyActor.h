// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
// generated.h 위에 추가 헤더파일 추가하기
#include "MyActor.generated.h"

UCLASS()
class REALGAMEPROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage")
	int32 TotalDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float DamageTimeInSeconds;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Damage")
	float DamagePerSecond;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CharacterName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bAttackable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	FString str;

	UFUNCTION(BlueprintNativeEvent, Category = "Damage")
	void CallFromCpp();
	virtual void CallFromCpp_Implementation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void TestFunction();

	UFUNCTION(BlueprintCallable, Category = "Damage")
	void CalculateDPS();

	virtual void PostInitProperties() override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};
