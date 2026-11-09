// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MapMassData.generated.h"

//マスの識別ID
UENUM(BlueprintType)
enum class EMapMassID : uint8
{
	NONE,
	START,
	MASS_1,
	MASS_2,
	MASS_3,
	MASS_4,
	BOSS
};

//マスの種類
UENUM(BlueprintType)
enum class EMapMassType : uint8
{
	NONE,
	START,
	BATTLE,
	TREASURE,
	SHOP,
	REST,
	BOSS
};

UCLASS(BlueprintType)
class GAMBLING_HERO_API UMapMassData : public UObject
{
    GENERATED_BODY()

protected:
    // マスの識別ID
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
    EMapMassID m_MassID = EMapMassID::NONE;

    // マスの種類
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
    EMapMassType m_MassType = EMapMassType::NONE;

    // 階層
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
    int32 m_Floor{ 0 };

    // 次に移動できるマス
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
    TArray<EMapMassID> m_NextMassIDs;

    // UI上の表示位置
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
    FVector2D m_Position = FVector2D::ZeroVector;

public:
    //変数取得関数
    UFUNCTION(BlueprintPure, Category = "Map")
    EMapMassID GetMassID() const 
    { return m_MassID; };
    UFUNCTION(BlueprintPure, Category = "Map")
    EMapMassType GetMassType() const
    { return m_MassType;};
    UFUNCTION(BlueprintPure, Category = "Map")
    int32 GetFloor()   const
    { return m_Floor;};
    UFUNCTION(BlueprintPure, Category = "Map")
    TArray<EMapMassID> GetMassIDs() const
    { return m_NextMassIDs; };
    UFUNCTION(BlueprintPure, Category = "Map")
    FVector2D GetMassPos() const 
    { return m_Position; };
   
    //変数設定関数
    void SetMassID(EMapMassID _ID) 
        {  m_MassID = _ID; };
    void SetMassType(EMapMassType _Type)
        {  m_MassType = _Type; };
    void SetFloor(int32 _Floor)
        {  m_Floor = _Floor;};
    void SetMapMassIDs
    (const TArray<EMapMassID>& _NextMass)
        { m_NextMassIDs = _NextMass;};
    void SetPosition(FVector2D _Pos)
        { m_Position = _Pos; };
};