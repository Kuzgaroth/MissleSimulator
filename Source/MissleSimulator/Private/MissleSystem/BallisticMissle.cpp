// Fill out your copyright notice in the Description page of Project Settings.


#include "MissleSimulator/Public/MissleSystem/BallisticMissle.h"

ABallisticMissle::ABallisticMissle()
{
	PrimaryActorTick.bCanEverTick = false;

	RocketMesh = CreateDefaultSubobject<USkeletalMeshComponent>("RoocketMesh");
	RootComponent = RocketMesh;

	/*RocketMovement = CreateDefaultSubobject<UProjectileMovementComponent>("RocketMovement");
	RocketMovement->SetUpdatedComponent(RocketMesh);*/
}

void ABallisticMissle::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABallisticMissle::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	RocketMesh->OnComponentHit.AddDynamic(this, &ABallisticMissle::OnGroundHit);
}

void ABallisticMissle::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	RocketMesh->OnComponentHit.RemoveDynamic(this, &ABallisticMissle::OnGroundHit);

	Super::EndPlay(EndPlayReason);
}

void ABallisticMissle::OnGroundHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
                                   UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

	//play explosion effect
	Destroy();
}

