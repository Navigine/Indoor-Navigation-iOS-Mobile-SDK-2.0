import UIKit

class CircularLoaderView: UIView {

  let circleRadius: CGFloat = 14.0
  let loadCircleStrokeColor: UIColor =
    UIColor(red: 0.129, green: 0.698, blue: 0.255, alpha: 1)
  let backingCircleStrokeColor: UIColor =
    UIColor(red: 0.818, green: 0.82, blue: 0.822, alpha: 1)
  

  let percentLabel: UILabel = UILabel.init(frame: .zero)
  let circlePathLayer = CAShapeLayer()
  let circleBackingLayer = CAShapeLayer()
  var progress: CGFloat {
    get {
      return circlePathLayer.strokeEnd
    }
    set {
      if newValue > 1 {
        circlePathLayer.strokeEnd = 1
        percentLabel.text = "100%"
      } else if newValue < 0 {
        circlePathLayer.strokeEnd = 0
      } else {
        circlePathLayer.strokeEnd = newValue
        percentLabel.text = String(Int(newValue * 100)) + "%"
      }
    }
  }
  
  // MARK:- Initializers
  override init(frame: CGRect) {
    super.init(frame: frame)
    configure()
  }
  
  required init?(coder aDecoder: NSCoder) {
    super.init(coder: aDecoder)
    configure()
  }
  
  override func layoutSubviews() {
    super.layoutSubviews()
    circlePathLayer.frame = bounds
    circlePathLayer.path = circlePath().cgPath
    
    circleBackingLayer.frame = bounds
    circleBackingLayer.path = circlePath().cgPath
    
    percentLabel.sizeToFit()
  }
  
  override func updateConstraints() {
    addConstraintsForPercentLabel()
    super.updateConstraints()
  }
  
  // MARK:- Setup
  private func configure() {
    progress = 0
    backgroundColor = .clear
    setupBackingCircle()
    setupLoadingCircle()
    setupPercentLabel()
    self.setNeedsUpdateConstraints()
  }
  
  private func setupLoadingCircle() {
    circlePathLayer.frame = bounds
    circlePathLayer.lineWidth = 1.5
    circlePathLayer.fillColor = UIColor.clear.cgColor
    circlePathLayer.strokeColor = loadCircleStrokeColor.cgColor
    layer.addSublayer(circlePathLayer)
  }
  
  private func setupBackingCircle() {
    circleBackingLayer.frame = bounds
    circleBackingLayer.lineWidth = 1.5
    circleBackingLayer.fillColor = UIColor.clear.cgColor
    circleBackingLayer.strokeColor = backingCircleStrokeColor.cgColor
    circleBackingLayer.strokeEnd = 1
    layer.addSublayer(circleBackingLayer)
  }
  
  private func setupPercentLabel() {
    // Setup percent label
    percentLabel.font = UIFont(name: "Circe-Bold", size: 9)
    percentLabel.textAlignment = .center
    percentLabel.textColor = loadCircleStrokeColor
    percentLabel.sizeToFit()
    percentLabel.translatesAutoresizingMaskIntoConstraints = false
    
    addSubview(percentLabel)
  }
  
  private func addConstraintsForPercentLabel() {
    let constraints = [
      percentLabel.centerXAnchor.constraint(equalTo: centerXAnchor),
      percentLabel.centerYAnchor.constraint(equalTo: centerYAnchor)]
    NSLayoutConstraint.activate(constraints)
  }
  
  private func circlePath() -> UIBezierPath {
    let circlePathBounds = circlePathLayer.bounds
    let arcCentre =
      CGPoint.init(x: circlePathBounds.midX,
                   y: circlePathBounds.midY)
    
    return UIBezierPath(arcCenter: arcCentre,
                        radius: circleRadius,
                        startAngle: -.pi / 2,
                        endAngle:  3 * .pi / 2,
                        clockwise: true)
  }
}

// MARK:- Unused
extension CircularLoaderView {
  func circleFrame() -> CGRect {
    var circleFrame =
      CGRect(x: 0, y: 0, width: 2 * circleRadius, height: 2 * circleRadius)
    let circlePathBounds = circlePathLayer.bounds
    circleFrame.origin.x = circlePathBounds.midX - circleFrame.midX
    circleFrame.origin.y = circlePathBounds.midY - circleFrame.midY
    
    return circleFrame
  }
}
