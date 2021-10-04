// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuSystem/ServerRow.h"

#include "Components/Button.h"

#include "MainMenu.h" 

void UServerRow::Setup(UMainMenu* Parent, uint32 Index)
{
	ParentMenu = Parent;
	ServerIndex = Index;
	
	RowButton->OnClicked.AddDynamic(this, &UServerRow::OnRowButtonClicked);
}

void UServerRow::OnRowButtonClicked()
{
	ParentMenu->SetServerIndex(ServerIndex);
}
