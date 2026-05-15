#include "options_setting_card.h"
#include <QtCore/QSignalBlocker>

OptionsSettingCard::OptionsSettingCard(QVariant configItem, QVariant *icon, QString title, QString content, QList<QString> texts, QWidget *parent) : ExpandSettingCard(icon, title, content, parent)
{
    this->texts =  texts.isEmpty() ? QList<QString>() : texts;
    this->configItem = configItem;
    this->configName = configItem.value<OptionsConfigItem*>()->name;
    this->choiceLabel = new QLabel(this);
    this->buttonGroup = new QButtonGroup(this);
    this->buttonGroup->setExclusive(true);
    this->isUpdatingValue = false;

    this->addWidget(this->choiceLabel);

    this->viewLayout->setSpacing(19);
    this->viewLayout->setContentsMargins(48, 18, 0, 18);
    for(int i = 0; i < texts.length(); i++){
        RadioButton *button = new RadioButton(texts.at(i), this->view);
        this->buttonGroup->addButton(button);
        this->viewLayout->addWidget(button);
        button->setProperty(this->configName.toUtf8(), configItem.value<OptionsConfigItem*>()->options().at(i));
    }

    this->_adjustViewSize();
    this->setValue(qconfig->get(this->configItem).value<QString>());
    connect(configItem.value<OptionsConfigItem*>(), &OptionsConfigItem::valueChanged, this, &OptionsSettingCard::setValue);
    connect(this->buttonGroup, QOverload<QAbstractButton*>::of(&QButtonGroup::buttonClicked), this, [this](QAbstractButton *b){
        RadioButton *radioButton = qobject_cast<RadioButton *>(b);
        if(!radioButton){
            return;
        }
        this->__onButtonClicked(radioButton);
    });
}
    

void OptionsSettingCard::__onButtonClicked(RadioButton *button)
{
    if(this->isUpdatingValue){
        return;
    }

    if(button->text() == this->choiceLabel->text()){
        return;
    }

    QString value = button->property(this->configName.toUtf8()).value<QString>();
    qconfig->set(this->configItem, QVariant::fromValue<QString>(value), true, false);

    this->choiceLabel->setText(button->text());
    this->choiceLabel->adjustSize();
    emit(this->optionChanged(this->configItem.value<OptionsConfigItem*>()));
}

void OptionsSettingCard::setValue(QString value)
{
    this->isUpdatingValue = true;
    for(int i = 0; i < this->buttonGroup->buttons().length(); i++){
        QAbstractButton *button = this->buttonGroup->buttons().at(i);
        bool isChecked = button->property(this->configName.toUtf8()).value<QString>() == value;
        if(!isChecked){
            continue;
        }

        QSignalBlocker groupBlocker(this->buttonGroup);
        QList<bool> previousSignalStates;
        for(QAbstractButton *blockedButton : this->buttonGroup->buttons()){
            previousSignalStates.append(blockedButton->blockSignals(true));
        }

        button->setChecked(true);
        this->choiceLabel->setText(button->text());
        this->choiceLabel->adjustSize();

        const QList<QAbstractButton *> buttons = this->buttonGroup->buttons();
        for(int j = 0; j < buttons.length(); ++j){
            buttons.at(j)->blockSignals(previousSignalStates.at(j));
        }
        break;
    }
    this->isUpdatingValue = false;
}
