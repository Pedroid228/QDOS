#pragma once

#include "GameFramework/HUD.h"
#include "QDOS_HUD.generated.h"

class UQDOS_Widget;

// AQDOS_HUD
//------------------------------------------------------------------------------------------------------------
UCLASS(Abstract) class QDOS_API AQDOS_HUD: public AHUD
{
	GENERATED_BODY()
	
public:
	AQDOS_HUD();
	
	virtual void BeginPlay();

protected:
	UPROPERTY(EditDefaultsOnly) TSubclassOf<UQDOS_Widget> QDOS_Widget_BP_Class;
	
private:
	UPROPERTY() UQDOS_Widget *QDOS_Widget = 0;
};
//------------------------------------------------------------------------------------------------------------
