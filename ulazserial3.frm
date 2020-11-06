object Form1: TForm1
  Left = 260
  Height = 379
  Top = 133
  Width = 703
  Caption = 'Form1'
  ClientHeight = 379
  ClientWidth = 703
  OnClose = FormClose
  OnCreate = FormCreate
  LCLVersion = '7.2'
  object btopen: TButton
    Left = 16
    Height = 32
    Top = 8
    Width = 129
    Caption = 'OPEN'
    OnClick = btopenClick
    TabOrder = 0
  end
  object Memo1: TMemo
    Left = 8
    Height = 308
    Top = 59
    Width = 184
    Lines.Strings = (
      ''
    )
    ScrollBars = ssAutoVertical
    TabOrder = 1
  end
  object edenviar: TEdit
    Left = 192
    Height = 28
    Top = 8
    Width = 109
    TabOrder = 2
    Text = 'a'
  end
  object btenviar: TButton
    Left = 314
    Height = 32
    Top = 8
    Width = 111
    Caption = 'ENVIAR'
    OnClick = btenviarClick
    TabOrder = 3
  end
  object ledrojo: TAdvLed
    Left = 672
    Height = 24
    Top = 8
    Width = 24
    State = lsDisabled
    Blink = False
  end
  object ledazul: TAdvLed
    Left = 672
    Height = 24
    Top = 32
    Width = 24
    State = lsDisabled
    Blink = False
  end
  object led13: TindLed
    Left = 672
    Height = 26
    Top = 59
    Width = 24
    LedValue = False
    Bevels = <    
      item
        HighlightColor = clBlack
        ShadowColor = clBlack
      end    
      item
        Width = 3
      end    
      item
        Style = bcLowered
      end    
      item
        HighlightColor = clBlack
        ShadowColor = clBlack
      end>
    LedColorOn = clLime
    LedColorOff = clGreen
    LedColorDisabled = 22963
    ShapeLedColorOn = clGreen
    ShapeLedColorOff = 16384
    ShapeLedColorDisabled = 13416
  end
  object termometro: TindGnouMeter
    Left = 200
    Height = 308
    Top = 59
    Width = 146
    Caption = 'termometro'
    SignalUnit = 'ºC'
    ValueMax = 100
    Digits = 0
    Increment = 10
    MarkerColor = clBlue
  end
  object higrometro: TindGnouMeter
    Left = 352
    Height = 308
    Top = 59
    Width = 127
    Caption = 'higrometro'
    SignalUnit = '%Hr'
    ValueMax = 100
    Digits = 0
    Increment = 10
    MarkerColor = clBlue
  end
  object mkservo: TmKnob
    Left = 512
    Height = 156
    Top = 156
    Width = 178
    AngleRange = arTop180
    BorderColor = clMoneyGreen
    BorderSpacing.Bottom = 1
    BorderSpacing.InnerBorder = 3
    FaceColor = clGradientActiveCaption
    Position = 0
    Max = 255
    OnChange = mkservoChange
  end
  object cbenviar: TComboBox
    Left = 432
    Height = 29
    Top = 8
    Width = 204
    ItemHeight = 0
    ItemIndex = 0
    Items.Strings = (
      'Encendeer Led 13'
      'Apagar Led 13'
      'Obtener Humedad'
      'Obtener Temperatura'
      ''
    )
    TabOrder = 5
    Text = 'Encendeer Led 13'
  end
end
