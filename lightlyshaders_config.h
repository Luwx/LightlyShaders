#pragma once

 
#include <kcmodule.h>

class LightlyShadersConfig : public KCModule
{
    Q_OBJECT
public:
    explicit LightlyShadersConfig(QWidget* parent = 0, const QVariantList& args = QVariantList());
    ~LightlyShadersConfig();
public slots:
    void save();
    void load();
    void defaults();

private:
    class Private;
    Private * const d;
    friend class Private;
};
