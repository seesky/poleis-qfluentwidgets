#include <QtCore/Qt>
#include <QtCore/QSize>
#include <QtCore/QPoint>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

#include "../components/widgets/state_tool_tip.h"
#include "../components/widgets/button.h"
#include "../common/icon.h"
#include "../common/style_sheet.h"

class Demo : public QWidget{
public:

    PushButton *button;
    StateToolTip *stateTooltip;
    Demo(){
        this->button = new PushButton(QString("Click Me"), this, nullptr);
        this->button->move(360, 225);
        this->stateTooltip = nullptr;
        connect(this->button, &ToggleToolButton::clicked, this, &Demo::onButtonClicked);
        this->resize(800, 300);
    };

public slots:
    void onButtonClicked(){
        if(this->stateTooltip != nullptr){
            this->stateTooltip->setContent(QString("模型训练完成啦 😆"));
            this->stateTooltip->setState(true);
            this->stateTooltip = nullptr;
        }else{
            this->stateTooltip = new StateToolTip(QString("正在训练模型"), QString("客官请耐心等待哦~~"), this);
            this->stateTooltip->move(510, 30);
            this->stateTooltip->show();
        }
        
    };
};




int main(int argc, char *argv[])
{
    QApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
    
    QApplication *app = new QApplication(argc, argv);
    Demo *w = new Demo();
    w->show();
    return app->exec();
}